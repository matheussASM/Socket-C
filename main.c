#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

/* Define a porta */
#define PORT 3000

/* define o tamanho do buffer */
#define BUFFER_LENGTH 1024

char code_200[] = "HTTP/1.1 200\nContent-type: text/html; charset=utf-8\n\n";
char code_404[] =  "HTTP/1.1 404\n\nPage Not found";

void abrir_html(int socket, char *page)
{
    FILE *html;
    char buff[5096];
    html = fopen(page, "r");
    fread(buff, 5096, 5096, (FILE*)html);

    send(socket, code_200, strlen(code_200) , 0 );
    send(socket, buff, strlen(buff) , 0 );
}

int main()
{
    int server_descritor;
    int new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_LENGTH];

    if ((server_descritor = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Erro não foi possivel criar o socket:");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_descritor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("Erro na configuração do socket:");
        exit(EXIT_FAILURE);
    }

    /* configuração do servidor */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_descritor, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("Erro na atribuição do endereço:");
        exit(EXIT_FAILURE);
    }
    if (listen(server_descritor, 3) < 0)
    {
        perror("Erro no listen:");
        exit(EXIT_FAILURE);
    }
    else
    {
    printf("Servidor iniciado com sucesso!\n");  
    }
    /* Looping para receber as conexões */
    while(1) {

        if ((new_socket = accept(server_descritor, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0)
        {
            perror("Não foi possivel aceitar a conexão:");
            exit(EXIT_FAILURE);
        }
        /* Recebe a informação sobre a requisição */
        read( new_socket , buffer, 1024);

        /* Realiza os tratamentos no buffer, para poder interpretar o tipo de requisição que está sendo feito */
        char *remover_primeira_linha = strtok(buffer, "\n");
        char *path;
        char *req_tratada = remover_primeira_linha;

        for(int i = 0; i < 2; i++) {
            path = strtok_r(req_tratada, " ", &req_tratada);

            if (i != 1) continue;

            if( strcmp(path, "/") == 0 ) {
                abrir_html(new_socket, "./index.html");
                break;
            }

            send(new_socket , code_404, strlen(code_404) , 0 );
        }

        close(new_socket);
    }

}