#include <stdio.h>

int arquivo_existe(const char *nome) {
  FILE *file;

  // Tenta abrir o arquivo
  file = fopen(nome, "r");

  // Arquivo inexistente
  if (file == NULL) return 0;

  // Fecha o arquivo
  fclose(file);

  // Arquivo existe
  return 1;
}

int main() {
  const char NOME_ARQUIVO[] = "notas.csv";
  int matricula, continuar_programa = 1;
  float notas[4], media;
  FILE *file;

  // Executa o programa enquanto o usuário pedir pra finalizar
  do {
    if (!arquivo_existe(NOME_ARQUIVO)) {
      // Abre o arquivo em mode de escrita
      file = fopen(NOME_ARQUIVO, "w");

      // Confere se o arquivo foi criado
      if (file == NULL) {
        printf("Erro ao tentar criar o arquivo.\n");
        return 1;
      }

      // Define as colunas no arquivo
      fprintf(file, "Matricula,Nota 1,Nota 2,Nota 3,Nota 4,Media\n");

      // Fecha o arquivo
      fclose(file);
    }

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &matricula);

    media = 0; // Média iniciada para cada aluno

    printf("Informe as notas do aluno:\n");
    for (int i = 0; i < 4; i++) {
      printf("Nota %d: ", i + 1);
      scanf("%f", &notas[i]); // Recebe cada nota
      media += notas[i];
    }
    media /= 4; // Calcula a média geral do aluno

    // TODO 3: Salvar os dados do aluno
    // -> Informar para o usuário o status da ação
    // Abre o arquivo em mode de anexação
    file = fopen(NOME_ARQUIVO, "a");

    // Confere se o arquivo foi aberto com êxito
    if (file == NULL) {
      printf("Erro ao abrir arquivo\n");
      return 1;
    }

    // Escreve os dados no arquivo
    fprintf(file, "%d,%.2f,%.2f,%.2f,%.2f,%.2f\n",
    matricula, notas[0], notas[1], notas[2], notas[3], media);

    // Fecha o arquivo para evitar problemas posteriores
    fclose(file);

    // Informa que a operação foi realizada com sucesso
    printf("As notas e a média do aluno foram salvas em '%s'.\n", NOME_ARQUIVO);

    // Confere se o programa deve continuar a execução
    printf("Digite [1] caso deseje continuar: ");
    scanf("%d", &continuar_programa);

  } while (continuar_programa == 1);

  printf("Programa finalizado.\n");

  return 0;
}
