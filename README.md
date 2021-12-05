# Socket-C
Este é um socket desenvolvido em C, que tem o intuito de atender a demanda solicitada pelo professor da matéria de sistemas distribuídos, os requisitos atendidos foram:

- [x] Um servidor HTTP servindo a uma única URL;
- [x] Um retorno “404 not found”, para quando a rota solicitada não existisse;
- [x] Um retorno “200 ok” servindo algum conteúdo, quando fosse solicitada a rota correta 

## 📋 Pré-requisitos
É necessario, estar instalado o interpretador da linguagem C na sua maquina, o download e mais informações sobre podem ser encontradas na propria página do [GCC](https://gcc.gnu.org/install/binaries.html) (Coleção de compiladores GNU).

## 🔧 Instalação
No terminal, clone o projeto:
```
git clone https://github.com/matheussASM/Socket-C.git
```
Após clonado, entre na pasta do projeto:
```
cd Socket-C
```
Compile o código, através do comando:
```
gcc main.c -o nome-do-programa
```
Após compilado, utilize o comando abaixo para iniciar o programa:
```
./nome-do-programa
```

Pronto, após isso você irá visualizar a mensagem "Servidor iniciado com sucesso!", em seu terminal, significando que o socket está disponível para uso.

## 📦 Consumindo o Socket
Caso queira consumir o socket deve  utilizar o método GET, recomendo a utilização de algum programa como [Insomnia](https://insomnia.rest/download), para um melhor teste dos retornos, então com o programa ou navegador, deve ser acessado a url:
```
http://localhost:3000/
```
Como Resultado esperado ele deve apresentar o arquivo index.html que está anexado neste repositório junto com um retorno "200 OK", para testarmos o retorno "404 NOT FOUND" é necessario inserir uma rota não existente, como no exemplo abaixo
```
http://localhost:3000/teste
```
Como resultado esperado ele deve apresentar um retorno "404 NOT FOUND"

## 🛠️ Construído com

C - É uma linguagem de programação compilada de propósito geral.

## ✒️ Autores

Desenvolvimento e documentado por Matheus Moreira

Linkedin - https://www.linkedin.com/in/matheus-antonio-9831b9157/
