#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 5  //Constante para Linhas da Matriz 'nome'
#define CARACTERES 200  //Constante para Colunas da Matriz 'nome'

int id[LINHAS];   //Vetor
char nome[LINHAS][CARACTERES];   //Matriz 5x200
char email[LINHAS][CARACTERES];  //Matriz 5x200
char sexo[LINHAS][CARACTERES];   //Matriz 5x200


int cadastro();   //Revisando
int listar();  //Completo
int login();    //Codando
//int remover_usuario();   ---> Falta Criar


int main(void)    //Incompleto
{
   while(1)
   {
      int opc;

      fflush(stdin);
      printf("\n--------------- Bem-Vindo ---------------");
      printf("\n\n1. Cadastrar\n2. Logar\n3. Listar\n4. Remover usuario\n5. Sair\n\nopcao -> ");
      scanf("%d", &opc);
      fflush(stdin);

      switch(opc)
      {
      case 1:
         cadastro();
         break;

      case 2:
         login();
         break;

      case 3:
         listar();
         break;

      case 4:
         //remover_usuario();
         break;

      case 5:
         exit(0);
         break;

      default:
         printf("\nERRO - Opcao invalida | Tente novamente");
         system("PAUSE");
         system("CLS");
         break;

      }

   }

   system("PAUSE");
   return 0;

}

int cadastro(void)   //Completo
{
   while(1)
   {      
      int qnt_usuarios, opc;

      printf("\nQuantos usuarios deseja cadastrar | 1 p/apenas um - 2p/muitos -> ");
      scanf("%d", &opc);

      if(opc == 1)
      {
         for(int l = 0; l < LINHAS; l++)
         {  
            if(id[l] == 0)
            {  
               id[l] = ++l;
               --l;

            }
            if(strlen(nome[l]) == 0)
            {
               fflush(stdin);
               printf("\nDigite o Nome -> ");
               scanf("%199[^\n]", &nome[l]);

            }
            if(strlen(email[l]) == 0)
            {
               fflush(stdin);
               printf("\nDigite o Email -> ");
               scanf("%199[^\n]", &email[l]);

            }
            if(strlen(sexo[l]) == 0)
            {
               fflush(stdin);
               printf("\nDigite o Sexo -> ");
               scanf("%199[^\n]", &sexo[l]);
               
               break;

            }

         }
         
         printf("\nCadastro realizado\n");
         system("PAUSE");
         system("CLS");

         break;

      }
      else if(opc == 2)
      {
         fflush(stdin);
         printf("\nQuantos usuarios deseja cadastrar | insira a quantidade (MAX.5) -> ");
         scanf("%d", &qnt_usuarios);

         char nomes[qnt_usuarios][CARACTERES];

         if(qnt_usuarios < 6 && qnt_usuarios > 0)
         {
            for(int l = 0; l < qnt_usuarios; l++)
            {
               if(id[l] == 0)
               {  
                  id[l] = ++l;
                  --l;

               }
               if(strlen(nome[l]) == 0)
               {
                  fflush(stdin);
                  printf("\n%d - Digite o Nome -> ", ++l);
                  --l;
                  scanf("%199[^\n]", &nome[l]);

               }
               if(strlen(email[l]) == 0)
               {
                  fflush(stdin);
                  printf("\n%d - Digite o Email -> ", ++l);
                  --l;
                  scanf("%199[^\n]", &email[l]);

               }
               if(strlen(sexo[l]) == 0)
               {
                  fflush(stdin);
                  printf("\n%d - Digite o Sexo -> ", ++l);
                  --l;
                  scanf("%199[^\n]", &sexo[l]);

               }

            }

         }
         else
         {
            printf("\nERRO - Valor MAIOR que 5 ou MENOR que 0");
            system("PAUSE");
            system("CLS");

            break;

         }

         printf("\nCadastros realizados com sucesso\n");
         system("PAUSE");
         system("CLS");

         break;

      }
      else
      {
         printf("\nERRO - Cadastro falhou\n");
         system("PAUSE");
         system("CLS");

      }

   }

   return 0;

}

int listar(void)   //Completo
{
   for(int i = 0; i < LINHAS; i++)
   {
      if(nome[i] > 0)
      {
         printf("\n%d - Nome -> %s\n", ++i, nome[i]);
         --i;
      }
      else
      {
         printf("\nNada foi Encontrado\n");

      }

   }

   system("PAUSE");
   system("CLS");
   return 0;
}

int login(void)   //Codando
{  
   char check[1][200];

   printf("\nInsira seu email -> ");
   fflush(stdin);
   scanf("%199[^\n]", &check);

   for(int i = 0; i < LINHAS; i++)
   {
      if(email[i] == check[1])
      {
         printf("\nLogin realizado com sucesso");
      }
      
   }   
   system("PAUSE");
   system("CLS");
   return 0;

}
