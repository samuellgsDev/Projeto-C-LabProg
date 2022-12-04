//Crie um sistema de mercado, que seja possivel adicionar e alterar o produto, e tambem remover o produto do estoque..
// utilize funções 
// utilize ponteiros
// utilize structs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct produto{
    char nome[50];
    int quantidade;
    int codigo;
    float preco;
};
void menu();
int a = 0;
void adicionar(struct produto *p);
void alterar(struct produto *p);
void remover(struct produto *p);
void listar(struct produto *p);
int main (){
  struct produto p[100];
  int opcao;
  do{
    menu();
    scanf("%d", &opcao);
    switch (opcao){
      case 1:
        adicionar(p);
        break;
      case 2:
        alterar(p);
        break;
      case 3:
        remover(p);
        break;
      case 4:
        listar(p);
        break;
      case 5:
        printf("Saindo do programa...");
        break;
      default:
        printf("Opcao invalida!");
        break;
      }
    }while (opcao != 5);
    return 0;
  }
void menu(){
  //fflush(stdin);
  printf("1 - Adicionar produto\n");
  printf("2 - Alterar produto\n");
  printf("3 - Remover\n");
  printf("4 - Listar produto\n");
  printf("5 - Sair\n");
  printf("Digite a opcao desejada: ");
  //while (getchar() != '\n');
}
void adicionar(struct produto *p){
  int i;
  for(i=0; i <100; i++){
    //fflush(stdin);
    if(p[i].codigo == 0) {
      printf("Digite o nome do produto: "); 
      //scanf("%s", p[i].nome);
    scanf(" %[^\n]%*c", p[i].nome); //para ler strings com espaços com scanset
      printf("Digite o codigo do produto: ");
      scanf("%d", &p[i].codigo);
      printf("Digite o preco do produto: ");
      scanf("%f",&p[i].preco);
      printf("Digite a quantidade do produto: ");
      scanf("%d", &p[i].quantidade);
      break;
    }
  }
  system("cls");
}

void alterar(struct produto *p){
  int i, codigo;
  printf("Digite o codigo do produto que deseja alterar: ");
  scanf("%d", &codigo);
  for(i=0; i <100; i++){
    if(p[i].codigo == 0){
      printf("Digite o nome do produto: ");
      scanf("%d" , &p[i].nome);
      printf("Digite o codigo do produto: ");
      scanf("%d", &p[i].codigo);
      printf("Digite o preco do produto: ");
      scanf("%f",&p[i].preco);
      printf("Digite a quantidade do produto: ");
      scanf("%d", &p[i].quantidade);
    } break;
  } //printf("&d", p[i].codigo);
}
void remover(struct produto *p){
  int i, codigo;
  printf("Digite o codigo do produto que voce deseja remover: ");
  scanf("%d", &codigo);
  for(i=0; i<100;i++){
    if(p[i].codigo == codigo){
      p[i].codigo = 0;
      break;
      
    }
  }
  
}
void listar(struct produto *p){
  int i; int lenght; int g;
  for(i=0; i<100; i++){
      if(p[i].codigo == 0){
        lenght = i;
        break;
    }
  }
  for(g=0; g<lenght; g++){
    printf("Nome: %s\n",p[g].nome);
    printf("Codigo: %d\n",p[g].codigo);
    printf("Preco: %.2f\n", p[g].preco);
    printf("Quantidade: %d\n,", p[g].quantidade);
    }
    
}