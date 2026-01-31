#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct ST_nodo {
   int info;
   struct ST_nodo *prox;
   
}nodo;

/* Utilizo uma struct de controle -- Pelo que vi pode ser feito sem -- para ter noção do tamanho 
da lista. Penso que nela pode haver outo ponteiro que sempre aponta para o fim da lista. 
mas, isso só seria útil para operações no final dela evitaria um laço para chegar lá. não sei...
*/

// algo simples para ser didático
typedef struct Lista_ {
   nodo *inicio;
   nodo *fim;
}Lista;

// funcoes:  

// * iserir
/*
A criação da lista encadeada pose seguir pelomenos 2 caminhos: 
   - Usando uma struct auxiliar de controle de lsitagem;
   - Sem essa struct.
 a primeira trabalha com ponteiros; a segunda, como não há axuilio para passar o 
 ponteiro real a ser trabalhado, requer o uso de ponteiros para ponteiro. Uma vez que ao passar
 o ponteiro como argumento, a unica coisa que está sendo passada por referência é o conteúdo do
 pontiro. O ponteiro em si é passado por valor. O probema é que nessa prática queremos mexer no
 ponteiro: logo, o uso do ponteiro para ponteiro pode ser usado. 
  No primeiro caso, ao encarregar a uma segunda struct  o trabalho de gerenciar o ponteiro inicial
  da lista podemos pasar apenas o ponteiro que aponta para a lista. Como o alvo do processo está no
  conteúdo da lista passar a o ponteiro por valor emite a referência do endereço da lista e permite 
  o acesso real à estrutura.
*/
void insere_in(Lista *list, int dados){
   // iserção requer um alocamento de memória referenciado com um ponteiro novo
    nodo * novo = (nodo*)malloc(sizeof(nodo)); 
   // > teste de confirmação de alocamento
   if (novo){
      // > Preenchimento
      // começo
      /*
      caso +, hora de preencher o no. não faz sentido criar um no em uma lista se não 
      for para preencher ou não me em em mente um motivo plausível para ocupar memória sem nada...
      */ 
      novo->info = dados; // Sim, os dados. Cê pode ter uma função externa a essa para o preenchimento
      // que pede ser aplicado dentro dessa função aqui, dispensando o argumento de entrada "dados".
      // Para fins didáticos, voltados ao nosso objetivo cá, o que estamos fazendo é o suficiente.

      // > inserção:
       if(list->inicio == NULL){
         list->inicio = novo;
         list->fim = novo; // será útil para opreções no fim... (n quero fazer esse laço)
         novo->prox = NULL;

       }else {
         novo->prox = list->inicio;
         list->inicio = novo;
        
        }
   }else{      
      system ("cls");
      printf("\nERRO: Memória não alocada\n");   
   }  
}

// fim
void insere_fm(Lista *list, int dados){
   nodo * novo = (nodo*)malloc(sizeof(nodo));
   if (novo){
      novo->info= dados;

      if (list->inicio== NULL){
         list->inicio = novo;
         list->fim = novo; 
         novo->prox = NULL;

      } else {
         list->fim->prox = novo;
         list-> fim = novo;
         novo->prox=NULL;

      }

   }else{
      printf("Erro: memória não alocada");
         }
}

// meio

/*
inserções no meio trabalham com uma referência na lista.
nos dados pode haver uma caracterísica que permita um tipo de ordenamento e ou identificação que possibilite
um inserção no meio.  como nome, ID. documento...  

Para isso, vamos considerar que o int dados se refere a um campo único da struct, que não possui
repetição.
*/
void insere_md (Lista *list, int dados, int ref){

   nodo * novo = (nodo*)malloc(sizeof(nodo));
   nodo *suporte;
   if (novo){
      novo->info= dados;
         // se for a 1° inserção
        if (list->inicio == NULL ){
            list->inicio = novo;
            list->fim = novo; 
            novo->prox = NULL;
      } else {
         // usaremos de uma variavel auxiliar para percorrer a lista sem alterar o ponteiro original 
         suporte = list->inicio;
         //eventualmete será encontrado o nó desejado se não encontrar e referência a inserção ocorre no fim... pq sim.
            while(suporte->info!= ref && suporte->prox!= NULL){
              suporte = suporte->prox;
         }
         if (suporte == list->fim){
         list->fim=novo;
         }
         novo->prox = suporte->prox;
         suporte->prox = novo;

            }

   }else{
      printf("Erro: memória não alocada");
         }

}


//* ler
// no
void printno(nodo * no){
   printf("\n- - - - - - - - - - - - - - - -\n");
   printf("Dados: %d", no->info);
   printf("\n- - - - - - - - - - - - - - - -\n");
}



// mostrar lista:

void imprime_ls(Lista ls){
   if (ls.inicio){
      system("cls");
      printf("\n=-=-=-=-=-=-=-=-=-=[LISTA]-=-=-=-=-=-=-=-=-=-=-=-\n\n");
      while (ls.inicio){
         printno(ls.inicio);
         ls.inicio = ls.inicio->prox;
         printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

         
      }
      printf("pressione enter para retornar ao menu");
      system ("pause");
      system("cls");
   }else{
      system("cls");
      printf("\nLISTA VAZIA\n");
      Sleep (500);
      system("cls");
   } 
}


// * Remover 
// liberar memória da lista
void lfree(nodo *no){
      nodo *aux = no;
      
   while(aux != NULL){
      aux =aux->prox;
      free(no);
   }
   free (aux);
}

// começo
// meio
// fim



int main (){

   int op,op1,x,y;
   Lista lista;
   lista.fim= NULL;
   lista.inicio = NULL;
   
   system("chcp 65001");
   
   do{
      char msg []= {"Saindo..."};

      printf ("\t\t\t\tMENU\n\n");
      printf("1- ADICIONAR     2- REMOVER\n3- LISTAR   0- SAIR\n");
      scanf("%d",&op);

      switch(op){
         case 0:
         // sair 
            system ("cls");
            printf("\n");
            for (int i=0; i <(int)strlen(msg); i++){
               printf("%c",msg[i]);
               Sleep(100);
            }
            lfree(lista.inicio);
            Sleep(100);
            system("cls");
            break;
         case 1:
            /* Poderia eu ter feito tudo em um swich só... mas, farei um dentro do outro 
            para poluir menos o terminal...
                     */ 
               do{

               system ("cls");
               printf("1- INÍCIO     2- MEIO\n3- FIM   \n0- VOLTAR\n");
               scanf("%d",&op1);
                     switch(op1){
                  case 0:

                     system ("cls");
                     break;

                  case 1:

                     system("cls");
                     printf("Digite o dado:");
                     scanf("%d", &x);
                     insere_in(&lista, x);
                     
                     system("cls");
                     break;

                  case 2:
                  
                     system("cls");
                     printf("Digite o dado:");
                     scanf("%d", &x);
                     printf("\nApós quem?\n");
                     scanf("%d", &y);
                     insere_md(&lista, x,y);

                     system("cls");
                     break;

                  case 3:

                     system("cls");
                     printf("Digite o dado:");
                     scanf("%d", &x);
                     insere_fm(&lista, x);
               
                     system("cls");
                     break;

                  default:
                     system("cls");
                     printf("\nENTRADA INVÁLIDA! Tente novamente.");
                     Sleep(100);
                     system("cls");
                     break;
               }

            }while(op1);


            break;
         case 2:
         system("cls");
         // sai da fila e mostra o próximo;
            break;
         case 3:
            system("cls");
            imprime_ls(lista);
            break;
         case 4:
           
            break;
         default:
            system("cls");
            printf("\nENTRADA INVÁLIDA! Tente novamente.");
            Sleep(100);
            system("cls");
            break;
      }
}while(op!=0);
   return 0;
}


