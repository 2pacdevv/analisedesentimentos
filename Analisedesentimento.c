#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAFOS 10
#define TAMANHO_PARAGRAFO 2000
#define MAX_PALAVRAS 100
#define MAX_TOKENS 500
#define MAX_TOKEN_LENGTH 100
void separar_palavras(char str[], char tokens[][MAX_TOKEN_LENGTH], int *contagem) {
    char *token;
    int numTokens = 0;
    const char delimiter[] = " ,.;:{}[]()\"\n";

    token = strtok(str, delimiter);

    while (token != NULL && numTokens < MAX_TOKENS) {
        strncpy(tokens[numTokens], token, MAX_TOKEN_LENGTH - 1);
        tokens[numTokens][MAX_TOKEN_LENGTH - 1] = '\0';

        for (int i = 0; tokens[numTokens][i]; i++) {
            tokens[numTokens][i] = tolower(tokens[numTokens][i]);
        }

        numTokens++;
        token = strtok(NULL, delimiter);
    }

    *contagem = numTokens;
}


void separar_sentenca(char str[], char tokens[][MAX_TOKEN_LENGTH], int *contagem) {
    char *token;
    int numTokens = 0;
    const char delimiter[] = ".";

    token = strtok(str, delimiter);

    while (token != NULL && numTokens < MAX_TOKENS) {
        strncpy(tokens[numTokens], token, MAX_TOKEN_LENGTH - 1);
        tokens[numTokens][MAX_TOKEN_LENGTH - 1] = '\0';

        for (int i = 0; tokens[numTokens][i]; i++) {
            tokens[numTokens][i] = tolower(tokens[numTokens][i]);
        }

        numTokens++;
        token = strtok(NULL, delimiter);
    }

    *contagem = numTokens;
}

int main(void) {
    int paragrafos;
    // printf("Informe o número de parágrafos: ");
    scanf("%d", &paragrafos);
    getchar();

    char texto[paragrafos][TAMANHO_PARAGRAFO];
    char texto_para_sentenca[MAX_PARAGRAFOS][TAMANHO_PARAGRAFO];

    for (int i = 0; i < paragrafos; i++) {
        // printf("Parágrafo %d: ", i + 1);
        fgets(texto[i], TAMANHO_PARAGRAFO, stdin);
    }

    for (int i = 0; i < paragrafos; i++) {
        strcpy(texto_para_sentenca[i], texto[i]);
    }

    // printf("\nParágrafos armazenados:\n");
    // for (int i = 0; i < paragrafos; i++) {
    //     printf("Parágrafo %d: %s", i + 1, texto_para_sentenca[i]);
    // }

    char tokens_texto[MAX_PARAGRAFOS][MAX_TOKENS][MAX_TOKEN_LENGTH];
    int contagem_tokens[MAX_PARAGRAFOS] ={0};

    for (int i = 0; i < paragrafos; i++) {
        separar_palavras(texto[i], tokens_texto[i], &contagem_tokens[i]);
    }

    char tokens_texto_sent[MAX_PARAGRAFOS][MAX_TOKENS][MAX_TOKEN_LENGTH];
    int contagem_tokens_sent[MAX_PARAGRAFOS] = {0};

    for (int i = 0; i < paragrafos; i++) {
        separar_sentenca(texto_para_sentenca[i], tokens_texto_sent[i], &contagem_tokens_sent[i]);
    }

    // printf("\nsentenças dos paragrafos: \n");
    // for (int i = 0; i < paragrafos; i++) {
    //     for (int j = 0; j < contagem_tokens_sent[i]; j++) {
    //         printf("sentença %d: %s\n", j + 1, tokens_texto_sent[i][j]);
    //     }
    // }

    int caracteres_por_sentenca[MAX_PARAGRAFOS][MAX_TOKENS] = {0};
    int palavras_por_sentenca[MAX_PARAGRAFOS][MAX_TOKENS] = {0};
    char tokens_de_cada_sentenca[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int contagem_tokens_sentenca_individual = 0;

    // Matriz para armazenar cópias das sentenças
    char tokens_texto_sentenca_comp[MAX_PARAGRAFOS][MAX_TOKENS][MAX_TOKEN_LENGTH];

    // Copiar tokens para a matriz de sentenças composta
    for (int i = 0; i < paragrafos; i++) {
        for (int j = 0; j < contagem_tokens_sent[i]; j++) {
            strcpy(tokens_texto_sentenca_comp[i][j], tokens_texto_sent[i][j]);
        }
    }

    // printf("\nsentenças dos paragrafos copiadas: \n");
    // for (int i = 0; i < paragrafos; i++) {
    //     for (int j = 0; j < contagem_tokens_sent[i]; j++) {
    //         printf("sentença bglh %d: %s\n", j + 1, tokens_texto_sentenca_comp[i][j]);
    //     }
    // }

    for (int i = 0; i < paragrafos; i++) {
        for (int j = 0; j < contagem_tokens_sent[i]; j++) {
            separar_palavras(tokens_texto_sent[i][j], tokens_de_cada_sentenca, &contagem_tokens_sentenca_individual);
            palavras_por_sentenca[i][j] = contagem_tokens_sentenca_individual;
            // printf("Parágrafo %d, Sentença %d: %d palavras\n", i + 1, j + 1, palavras_por_sentenca[i][j]);
            int caracteres = 0;
            for (int k = 0; k < contagem_tokens_sentenca_individual; k++) {
                caracteres += strlen(tokens_de_cada_sentenca[k]);
            }
            caracteres_por_sentenca[i][j] = caracteres;
            // printf("Parágrafo %d, Sentença %d: %d palavras, %d caracteres\n", i + 1, j + 1, palavras_por_sentenca[i][j], caracteres_por_sentenca[i][j]);
        }
    }

  for(int i = 0; i < paragrafos; i++){
     for(int j =0; j < contagem_tokens_sent[i]; j++){
       if(palavras_por_sentenca[i][j] == 0){
         palavras_por_sentenca[i][j] = 200;
       }
     }

  }
  int indice_paragrafo_maior_palavra = 0;
  int indice_sentenca_maior_palavra = 0;
  int menor_numero_palavra = 20000;
  for (int i = 0; i < paragrafos; i++) {
      for (int j = 0; j < contagem_tokens_sent[i]; j++) {
          if (palavras_por_sentenca[i][j] < menor_numero_palavra) {
              menor_numero_palavra = palavras_por_sentenca[i][j];
              indice_paragrafo_maior_palavra = i;
              indice_sentenca_maior_palavra = j;
          }
      }
  }
//   printf("Parágrafo da maior sentença de palavras: %d\n", indice_paragrafo_maior_palavra + 1);
//   printf("Índice da maior sentença de palavras: %d\n", indice_sentenca_maior_palavra + 1);
    int indice_paragrafo_maior = 0;
    int indice_sentenca_maior = 0;
    int maior_numero_caracteres = 0;
    for (int i = 0; i < paragrafos; i++) {
        for (int j = 0; j < contagem_tokens_sent[i]; j++) {
            if (caracteres_por_sentenca[i][j] > maior_numero_caracteres) {
                maior_numero_caracteres = caracteres_por_sentenca[i][j];
                indice_paragrafo_maior = i;
                indice_sentenca_maior = j;
            }
        }
    }
    // printf("Parágrafo da maior sentença: %d\n", indice_paragrafo_maior + 1);
    // printf("Índice da maior sentença: %d\n", indice_sentenca_maior + 1);

    char palavras_positivas[MAX_PALAVRAS][200];
    char tokens_positivos[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int contagem_tokens_positivos = 0;

    // Recebendo as palavras positivas
    // printf("Informe as palavras positivas (separadas por espaços): ");
    fgets(palavras_positivas[0], 200, stdin);
    separar_palavras(palavras_positivas[0], tokens_positivos, &contagem_tokens_positivos);

    // printf("\nTokens positivos:\n");
    // for (int j = 0; j < contagem_tokens_positivos; j++) {
    //     printf("%s\n", tokens_positivos[j]);
    // }
    // printf("\n");

    int contagem_palavras_positivas[MAX_PARAGRAFOS] = {0};
    int contagem_pos = 0;
    for (int i = 0; i < paragrafos; i++) {
        for (int j = 0; j < contagem_tokens[i]; j++) {
            for (int k = 0; k < contagem_tokens_positivos; k++) {
                if (strcmp(tokens_texto[i][j], tokens_positivos[k]) == 0) {
                    contagem_palavras_positivas[i]++;
                    contagem_pos++;
                    break;
                }
            }
        }
    }

  char tokens_sentenca_maior[MAX_TOKENS][MAX_TOKEN_LENGTH];
  int contagem_tokens_sentenca_maior = 0;
int frequencia_positivas_maior_sentenca = 0;
    // Calcular a frequência de palavras positivas na maior sentença
    separar_palavras(tokens_texto_sentenca_comp[indice_paragrafo_maior][indice_sentenca_maior], tokens_sentenca_maior, &contagem_tokens_sentenca_maior);
    for (int j = 0; j < contagem_tokens_sentenca_maior; j++) {
        for (int k = 0; k < contagem_tokens_positivos; k++) {
            if (strcmp(tokens_sentenca_maior[j], tokens_positivos[k]) == 0) {
                frequencia_positivas_maior_sentenca++;
                break;
            }
        }
    }


   char tokens_sentenca_maior_palavra[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int contagem_tokens_sentenca_maior_palavra = 0;
  int frequencia_positivas_maior_sentenca_palavra = 0;
      // Calcular a frequência de palavras positivas na maior sentença
      separar_palavras(tokens_texto_sentenca_comp[indice_paragrafo_maior_palavra][indice_sentenca_maior_palavra], tokens_sentenca_maior_palavra, &contagem_tokens_sentenca_maior_palavra);
      for (int j = 0; j < contagem_tokens_sentenca_maior_palavra; j++) {
          for (int k = 0; k < contagem_tokens_positivos; k++) {
              if (strcmp(tokens_sentenca_maior_palavra[j], tokens_positivos[k]) == 0) {
                  frequencia_positivas_maior_sentenca_palavra++;
                  break;
              }
          }
}


// printf("frequencia de palavras positivas na maior sentença de palavra: %d", frequencia_positivas_maior_sentenca_palavra);



//   printf("Frequência de palavras positivas na maior sentença: %d\n", frequencia_positivas_maior_sentenca);



    char palavras_negativas[MAX_PALAVRAS][200];
    char tokens_negativos[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int contagem_tokens_negativos = 0;

    // Recebendo as palavras negativas

    fgets(palavras_negativas[0], 200, stdin);
    separar_palavras(palavras_negativas[0], tokens_negativos, &contagem_tokens_negativos);

    // printf("\nTokens negativos:\n");
    // for (int j = 0; j < contagem_tokens_negativos; j++) {
    //     printf("%s\n", tokens_negativos[j]);
    // }
    // printf("\n");

    int contagem_palavras_negativas[MAX_PARAGRAFOS] = {0};
    int contagem_neg = 0;
    for (int i = 0; i < paragrafos; i++) {
        for (int j = 0; j < contagem_tokens[i]; j++) {
            for (int k = 0; k < contagem_tokens_negativos; k++) {
                if (strcmp(tokens_texto[i][j], tokens_negativos[k]) == 0) {
                    contagem_palavras_negativas[i]++;
                    contagem_neg++;
                    break;
                }
            }
        }
    }

    // for (int i = 0; i < paragrafos; i++) {
    //     printf("Frequência de palavras positivas no parágrafo %d: %d\n", i + 1, contagem_palavras_positivas[i]);
    // }
    // for (int i = 0; i < paragrafos; i++) {
    //     printf("Frequência de palavras negativas no parágrafo %d: %d\n", i + 1, contagem_palavras_negativas[i]);
    // }




int frequencia_negativa_maior_sentenca_palavra = 0;
        for (int j = 0; j < contagem_tokens_sentenca_maior_palavra; j++) {
            for (int k = 0; k < contagem_tokens_negativos; k++) {
                if (strcmp(tokens_sentenca_maior_palavra[j], tokens_negativos[k]) == 0) {
                    frequencia_negativa_maior_sentenca_palavra++;
                    break;
                }
            }
  }

int frequencia_negativas_maior_sentenca = 0;
    // Calcular a frequência de palavras positivas na maior sentença
    for (int j = 0; j < contagem_tokens_sentenca_maior; j++) {
        for (int k = 0; k < contagem_tokens_negativos; k++) {
            if (strcmp(tokens_sentenca_maior[j], tokens_negativos[k]) == 0) {
                frequencia_negativas_maior_sentenca++;
                break;
            }
        }
    }
int quantidade_questoes;
scanf("%d", &quantidade_questoes);
  int paragrafoooo;
  int questao;
  int questoes[quantidade_questoes];
  int questoes_paragrafo[quantidade_questoes];
  int segundo_contador = 0;
for(int i = 0; i < quantidade_questoes; i++){
  scanf("%d", &questao);
  if(questao == 2){
    scanf(" %d", &paragrafoooo);
    questoes[i] = questao;
    questoes_paragrafo[segundo_contador] = paragrafoooo;
    segundo_contador++;
  }
   else if(questao != 2){
     questoes[i] = questao;
   }
}
segundo_contador = 0;
for(int i = 0; i < quantidade_questoes; i++){
  if(questoes[i] == 1){
    if(contagem_pos - contagem_neg > 3 || contagem_pos > 0 && contagem_neg == 0){
      printf("%d Palavras positivas, %d Palavras negativas: Polaridade positiva\n", contagem_pos, contagem_neg);
    } 
    else if(contagem_neg - contagem_pos > 3 || contagem_neg > 0 && contagem_pos == 0){
      printf("%d Palavras positivas, %d Palavras negativas: Polaridade negativa\n", contagem_pos, contagem_neg);
    }
    else{
      printf("%d Palavras positivas, %d Palavras negativas: Polaridade neutra\n", contagem_pos, contagem_neg);
    }
  }
  else if(questoes[i] == 2){
    if(contagem_palavras_positivas[questoes_paragrafo[segundo_contador]] - contagem_palavras_negativas[questoes_paragrafo[segundo_contador]] > 3 || contagem_palavras_positivas[questoes_paragrafo[segundo_contador]] > 0 && contagem_palavras_negativas[questoes_paragrafo[segundo_contador]] == 0 ){
       printf("%d Palavras positivas, %d Palavras negativas: Polaridade positiva\n", contagem_palavras_positivas[questoes_paragrafo[segundo_contador]], contagem_palavras_negativas[questoes_paragrafo[segundo_contador]]);
    }
  else if(contagem_palavras_negativas[questoes_paragrafo[segundo_contador]] - contagem_palavras_positivas[questoes_paragrafo[segundo_contador]] > 3 || contagem_palavras_negativas[questoes_paragrafo[segundo_contador]] > 0 && contagem_palavras_positivas[questoes_paragrafo[segundo_contador]] == 0 ){
       printf("%d Palavras positivas, %d Palavras negativas: Polaridade negativa\n", contagem_palavras_positivas[questoes_paragrafo[segundo_contador]], contagem_palavras_negativas[questoes_paragrafo[segundo_contador]]);
    }
  else{
     printf("%d Palavras positivas, %d Palavras negativas: Polaridade negativa\n", contagem_palavras_positivas[questoes_paragrafo[segundo_contador]], contagem_palavras_negativas[questoes_paragrafo[segundo_contador]]);
  }
    segundo_contador++;
  }

else if (questoes[i] == 3){
  if(frequencia_positivas_maior_sentenca - frequencia_negativas_maior_sentenca > 3 || frequencia_positivas_maior_sentenca > 0 && frequencia_negativas_maior_sentenca == 0){
    printf("%d palavras positivas, %d Palavras negativas: Polaridade positiva\n", frequencia_positivas_maior_sentenca, frequencia_negativas_maior_sentenca);
  }
  else if(frequencia_negativas_maior_sentenca - frequencia_positivas_maior_sentenca > 3 || frequencia_negativas_maior_sentenca > 0 && frequencia_positivas_maior_sentenca == 0){
     printf("%d palavras positivas, %d Palavras negativas: Polaridade negativas\n", frequencia_positivas_maior_sentenca, frequencia_negativas_maior_sentenca);
  }
  else{
    printf("%d palavras positivas, %d Palavras negativas: Polaridade neutra\n", frequencia_positivas_maior_sentenca, frequencia_negativas_maior_sentenca);
  }
}
else if(questoes[i] == 4){
  if(frequencia_positivas_maior_sentenca_palavra - frequencia_negativa_maior_sentenca_palavra > 3 || frequencia_positivas_maior_sentenca_palavra > 0 && frequencia_negativa_maior_sentenca_palavra == 0){
    printf("%d palavras positivas, %d Palavras negativas: Polaridade positiva\n", frequencia_positivas_maior_sentenca_palavra, frequencia_negativa_maior_sentenca_palavra);
  }
  else if(frequencia_negativa_maior_sentenca_palavra - frequencia_positivas_maior_sentenca_palavra > 3 || frequencia_negativa_maior_sentenca_palavra > 0 && frequencia_positivas_maior_sentenca_palavra == 0){
    printf("%d palavras positivas, %d Palavras negativas: Polaridade negativa\n", frequencia_positivas_maior_sentenca_palavra, frequencia_negativa_maior_sentenca_palavra);
  }
  else{
    printf("%d palavras positivas, %d Palavras negativas: Polaridade neutra\n", frequencia_positivas_maior_sentenca_palavra, frequencia_negativa_maior_sentenca_palavra);
  }
}
}
    return 0;
}
