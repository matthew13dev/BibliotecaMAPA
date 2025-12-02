#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ====== STRUCTS DO SISTEMA ======

typedef struct {
    int codigo;
    char titulo[100];
    char autor[80];
    char editora[60];
    int ano;
    int exemplares;
    int status;
} Livro;

typedef struct {
    int matricula;
    char nome[100];
    char curso[50];
    char telefone[15];
    int diaCadastro;
    int mesCadastro;
    int anoCadastro;
} Usuario;

typedef struct {
    int codigoEmprestimo;
    int matriculaUsuario;
    int codigoLivro;
    int diaEmprestimo;
    int mesEmprestimo;
    int anoEmprestimo;
    int diaDevolucaoPrevista;
    int mesDevolucaoPrevista;
    int anoDevolucaoPrevista;
    int status;
} Emprestimo;

// ====== FIM DAS STRUCTS ======


// ===== CONTANSTES ======

#define MAX_LIVROS 1000
#define MAX_USUARIOS 1000
#define MAX_EMPRESTIMOS 1000

Livro livros[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];
Emprestimo emprestimos[MAX_EMPRESTIMOS];

int totalLivros = 0;
int totalUsuarios = 0;
int totalEmprestimos = 0;



// ====== PROTÓTIPOS DAS FUNÇÕES DE ARQUIVO ======
void salvarLivros();
void salvarUsuarios();
void salvarEmprestimos();
void salvarTudo();
void carregarLivros();
void carregarUsuarios();
void carregarEmprestimos();
void carregarTudo();
// ===============================================



// ============ FUNCOES =======

// cadastrar livro
void cadastrarLivro() {
    if (totalLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido!\n");
        return;
    }

    Livro l;

    printf("\n--- Cadastro de Livro ---\n");
    printf("Codigo: ");
    scanf("%d", &l.codigo);

    printf("Titulo: ");
    getchar(); 
    fgets(l.titulo, 100, stdin);
    l.titulo[strcspn(l.titulo, "\n")] = '\0';

    printf("Autor: ");
    fgets(l.autor, 80, stdin);
    l.autor[strcspn(l.autor, "\n")] = '\0';

    printf("Editora: ");
    fgets(l.editora, 60, stdin);
    l.editora[strcspn(l.editora, "\n")] = '\0';

    printf("Ano de publicacao: ");
    scanf("%d", &l.ano);

    printf("Quantidade de exemplares: ");
    scanf("%d", &l.exemplares);

    l.status = 0; // disponível

    livros[totalLivros] = l;
    totalLivros++;

    printf("\nLivro cadastrado com sucesso!\n");
    salvarLivros();
}

// ==== Cadastrar Usuarios
void cadastrarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido!\n");
        return;
    }

    Usuario u;

    printf("\n--- Cadastro de Usuario ---\n");
    printf("Matricula: ");
    scanf("%d", &u.matricula);

    printf("Nome: ");
    getchar();
    fgets(u.nome, 100, stdin);
    u.nome[strcspn(u.nome, "\n")] = '\0';

    printf("Curso: ");
    fgets(u.curso, 50, stdin);
    u.curso[strcspn(u.curso, "\n")] = '\0';

    printf("Telefone: ");
    fgets(u.telefone, 15, stdin);
    u.telefone[strcspn(u.telefone, "\n")] = '\0';

    printf("Data de cadastro (dia mes ano): ");
    scanf("%d %d %d", &u.diaCadastro, &u.mesCadastro, &u.anoCadastro);

    usuarios[totalUsuarios] = u;
    totalUsuarios++;

    printf("\nUsuario cadastrado com sucesso!\n");
    salvarUsuarios();
}

// ==== Cadastrar Emprestimos
void cadastrarEmprestimo() {
    if (totalEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Limite de emprestimos atingido!\n");
        return;
    }

    Emprestimo e;

    printf("\n--- Registrar Emprestimo ---\n");

    printf("Codigo do emprestimo: ");
    scanf("%d", &e.codigoEmprestimo);

    printf("Matricula do usuario: ");
    scanf("%d", &e.matriculaUsuario);

    printf("Codigo do livro: ");
    scanf("%d", &e.codigoLivro);

    printf("Data do emprestimo (dia mes ano): ");
    scanf("%d %d %d", &e.diaEmprestimo, &e.mesEmprestimo, &e.anoEmprestimo);

    // devolução = 7 dias depois (simples, sem calendário real)
    e.diaDevolucaoPrevista = e.diaEmprestimo + 7;
    e.mesDevolucaoPrevista = e.mesEmprestimo;
    e.anoDevolucaoPrevista = e.anoEmprestimo;

    e.status = 0; // ativo

    emprestimos[totalEmprestimos] = e;
    totalEmprestimos++;

    printf("\nEmprestimo registrado com sucesso!\n");
    salvarEmprestimos();
}


// =========== Persistencia dos Dados em arquivos de TXT =================


// ====== FUNÇÕES PARA SALVAR EM ARQUIVO ======

void salvarLivros() {
    FILE *arquivo = fopen("livros.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de livros!\n");
        return;
    }
    
    int i;
    for (i = 0; i < totalLivros; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%d;%d;%d\n",
                livros[i].codigo,
                livros[i].titulo,
                livros[i].autor,
                livros[i].editora,
                livros[i].ano,
                livros[i].exemplares,
                livros[i].status);
    }
    
    fclose(arquivo);
}

void salvarUsuarios() {
    FILE *arquivo = fopen("usuarios.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de usuarios!\n");
        return;
    }
    
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%d;%d;%d\n",
                usuarios[i].matricula,
                usuarios[i].nome,
                usuarios[i].curso,
                usuarios[i].telefone,
                usuarios[i].diaCadastro,
                usuarios[i].mesCadastro,
                usuarios[i].anoCadastro);
    }
    
    fclose(arquivo);
}

void salvarEmprestimos() {
    FILE *arquivo = fopen("emprestimos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de emprestimos!\n");
        return;
    }
    
    int i;
    for (i = 0; i < totalEmprestimos; i++) {
        fprintf(arquivo, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n",
                emprestimos[i].codigoEmprestimo,
                emprestimos[i].matriculaUsuario,
                emprestimos[i].codigoLivro,
                emprestimos[i].diaEmprestimo,
                emprestimos[i].mesEmprestimo,
                emprestimos[i].anoEmprestimo,
                emprestimos[i].diaDevolucaoPrevista,
                emprestimos[i].mesDevolucaoPrevista,
                emprestimos[i].anoDevolucaoPrevista,
                emprestimos[i].status);
    }
    
    fclose(arquivo);
}

// Função para salvar TUDO
void salvarTudo() {
    salvarLivros();
    salvarUsuarios();
    salvarEmprestimos();
    printf("Dados salvos com sucesso!\n");
}


// ====== FUNÇÕES PARA CARREGAR DO ARQUIVO ======

void carregarLivros() {
    FILE *arquivo = fopen("livros.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de livros nao encontrado. Iniciando vazio.\n");
        return;
    }
    
    totalLivros = 0;
    while (!feof(arquivo) && totalLivros < MAX_LIVROS) {
        Livro l;
        if (fscanf(arquivo, "%d;%99[^;];%79[^;];%59[^;];%d;%d;%d\n",
                   &l.codigo,
                   l.titulo,
                   l.autor,
                   l.editora,
                   &l.ano,
                   &l.exemplares,
                   &l.status) == 7) {
            livros[totalLivros] = l;
            totalLivros++;
        }
    }
    
    fclose(arquivo);
    printf("Livros carregados: %d\n", totalLivros);
}

void carregarUsuarios() {
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de usuarios nao encontrado. Iniciando vazio.\n");
        return;
    }
    
    totalUsuarios = 0;
    while (!feof(arquivo) && totalUsuarios < MAX_USUARIOS) {
        Usuario u;
        if (fscanf(arquivo, "%d;%99[^;];%49[^;];%14[^;];%d;%d;%d\n",
                   &u.matricula,
                   u.nome,
                   u.curso,
                   u.telefone,
                   &u.diaCadastro,
                   &u.mesCadastro,
                   &u.anoCadastro) == 7) {
            usuarios[totalUsuarios] = u;
            totalUsuarios++;
        }
    }
    
    fclose(arquivo);
    printf("Usuarios carregados: %d\n", totalUsuarios);
}

void carregarEmprestimos() {
    FILE *arquivo = fopen("emprestimos.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de emprestimos nao encontrado. Iniciando vazio.\n");
        return;
    }
    
    totalEmprestimos = 0;
    while (!feof(arquivo) && totalEmprestimos < MAX_EMPRESTIMOS) {
        Emprestimo e;
        if (fscanf(arquivo, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n",
                   &e.codigoEmprestimo,
                   &e.matriculaUsuario,
                   &e.codigoLivro,
                   &e.diaEmprestimo,
                   &e.mesEmprestimo,
                   &e.anoEmprestimo,
                   &e.diaDevolucaoPrevista,
                   &e.mesDevolucaoPrevista,
                   &e.anoDevolucaoPrevista,
                   &e.status) == 10) {
            emprestimos[totalEmprestimos] = e;
            totalEmprestimos++;
        }
    }
    
    fclose(arquivo);
    printf("Emprestimos carregados: %d\n", totalEmprestimos);
}

// Função para carregar TUDO
void carregarTudo() {
    carregarLivros();
    carregarUsuarios();
    carregarEmprestimos();
}




// ==== MENU ======

void listarLivros() {
    printf("\n--- Lista de Livros ---\n");
    if(totalLivros == 0){
    	printf("Lista vazia\n");
    	return;
	}
	int i;
    for (i = 0; i < totalLivros; i++) {
        printf("Codigo: %d | Titulo: %s | Autor: %s | Ano: %d | Exemplares: %d\n",
               livros[i].codigo, livros[i].titulo, livros[i].autor,
               livros[i].ano, livros[i].exemplares);
    }
}

void listarUsuarios() {
    printf("\n--- Lista de Usuarios ---\n");
    if(totalLivros == 0){
    	printf("Lista vazia\n");
    	return;
	}
	int i;
    for (i = 0; i < totalUsuarios; i++) {
        printf("Matricula: %d | Nome: %s | Curso: %s | Telefone: %s\n",
               usuarios[i].matricula, usuarios[i].nome, 
               usuarios[i].curso, usuarios[i].telefone);
    }
}

void listarEmprestimos() {
    printf("\n--- Emprestimos Ativos ---\n");
    if(totalLivros == 0){
    	printf("Lista vazia\n");
    	return;
	}
	
	int i;
    for (i = 0; i < totalEmprestimos; i++) {
        printf("Codigo: %d | Usuario: %d | Livro: %d | Prev devolucao: %d/%d/%d\n",
               emprestimos[i].codigoEmprestimo,
               emprestimos[i].matriculaUsuario,
               emprestimos[i].codigoLivro,
               emprestimos[i].diaDevolucaoPrevista,
               emprestimos[i].mesDevolucaoPrevista,
               emprestimos[i].anoDevolucaoPrevista
        );
    }
}


void menu() {
    int opcao;

    do {
        printf("\n=== Sistema Biblioteca ===\n");
        printf("1 - Cadastrar Livro\n");
        printf("2 - Cadastrar Usuario\n");
        printf("3 - Cadastrar Emprestimo\n");
        printf("4 - Listar Livros\n");
        printf("5 - Listar Usuarios\n");
        printf("6 - Listar Emprestimos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarLivro(); break;
            case 2: cadastrarUsuario(); break;
            case 3: cadastrarEmprestimo(); break;
            case 4: listarLivros(); break;
            case 5: listarUsuarios(); break;
            case 6: listarEmprestimos(); break;
            case 0: 
            	salvarTudo(); // salva ao sair
				printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}



// ====== MAIN ============
int main() {

	int opcao;
	
	// carrega os dados antes de iniciar
	carregarTudo();
	
	
	menu();
    return 0;
}

