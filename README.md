📚 Sistema de Biblioteca em C
Sistema simples de gerenciamento de biblioteca com persistência em arquivos

🎯 Funcionalidades
Módulo	Recursos
📖 Livros	Cadastro, listagem, controle de exemplares
👥 Usuários	Cadastro com dados acadêmicos
🔄 Empréstimos	Registro com datas automáticas
💾 Dados	Salva automaticamente em arquivos .txt
🚀 Como Usar
▶️ Executar
bash
# Compilar
gcc -o biblioteca main.c

# Executar
./biblioteca
📋 Menu Principal
text
1. Cadastrar Livro
2. Cadastrar Usuário
3. Registrar Empréstimo
4. Listar Livros
5. Listar Usuários
6. Listar Empréstimos
7. Salvar Backup
0. Sair
📁 Estrutura de Arquivos
text
biblioteca/
├── main.c              # Código fonte
├── biblioteca.exe      # Executável (Windows)
├── livros.txt          # Dados dos livros (auto)
├── usuarios.txt        # Dados dos usuários (auto)
└── emprestimos.txt     # Dados de empréstimos (auto)
⚙️ Requisitos
Compilador C (GCC, MinGW, ou similar)

Windows/Linux/Mac (compilado com GCC)

🛠️ Compilação
Dev-C++
Abra main.c

Execute → Compile & Run (F11)

Terminal Linux/Mac
bash
gcc main.c -o biblioteca
./biblioteca
Prompt do Windows (MinGW)
cmd
gcc main.c -o biblioteca.exe
biblioteca.exe
🔧 Solução de Problemas
❌ "for loop initial declarations"
Solução: No Dev-C++, vá em:

text
Tools → Compiler Options → Adicione "-std=c99"
❌ Arquivos .txt não são criados
Solução: Execute como administrador ou verifique permissões da pasta

❌ Dados desaparecem
Solução: Use sempre a opção 7 (Salvar) antes de sair

📸 Exemplo de Uso
c
// Cadastrando um livro:
Código: 101
Título: O Senhor dos Anéis
Autor: J.R.R. Tolkien
Ano: 1954
Exemplares: 5
✅ Livro cadastrado!
📊 Dados Salvos
Os arquivos usam formato simples:

livros.txt

text
101;O Senhor dos Anéis;J.R.R. Tolkien;Martins;1954;5;0
usuarios.txt

text
2024001;João Silva;Computação;11999999999;25;3;2024
