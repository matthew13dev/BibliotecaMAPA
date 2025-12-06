**Sistema de Biblioteca em C**
- Sistema simples de gerenciamento de biblioteca com persistência em arquivos.

**Funcionalidades**
- Cadastro de livros

- Cadastro de usuários

- Registro de empréstimos

- Listagem de dados

- Salva automaticamente em arquivos .txt

- Funcoes de busca

**Como Usar**
- **Compilar e Executar:**
gcc -o biblioteca main.c
./biblioteca

- **No Dev-C++:**
Abra main.c
Pressione F11 (Compile & Run)


**Menu do Sistema**
- Cadastrar Livro
- Cadastrar Usuário
- Cadastrar Empréstimo
- Listar Livros
- Listar Usuários
- Listar Empréstimos
- Salvar dados (backup)
- Sair



**Estrutura de Arquivos**
- main.c - código fonte principal

- biblioteca.exe - executável

- livros.txt - dados dos livros (gerado automaticamente)

- usuarios.txt - dados dos usuários (gerado automaticamente)

- emprestimos.txt - dados de empréstimos (gerado automaticamente)

**Formato dos Arquivos**
- **livros.txt**
codigo;titulo;autor;editora;ano;exemplares;status

- **usuarios.txt**
matricula;nome;curso;telefone;dia;mes;ano

- **emprestimos.txt**
codigoEmprestimo;matriculaUsuario;codigoLivro;diaE;mesE;anoE;diaD;mesD;anoD;status

