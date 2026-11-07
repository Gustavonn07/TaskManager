# TaskManager

Um gerenciador de tarefas desenvolvido em **C++**, com interface de linha de comando (CLI), como projeto de estudo e aplicação prática de conceitos de programação, organização de software e gerenciamento de dependências com CMake.

## Sobre o projeto

O TaskManager tem como objetivo permitir o gerenciamento de tarefas, oferecendo operações para criação, edição, remoção e atualização de progresso.

O projeto está sendo desenvolvido com uma arquitetura modular, separando responsabilidades em bibliotecas independentes, facilitando a manutenção e a evolução do sistema.

## Tecnologias utilizadas

- **C++20** — linguagem principal.
- **CMake** — configuração do sistema de build e gerenciamento das bibliotecas.
- **GCC (MSYS2 UCRT64)** — compilador utilizado no desenvolvimento.
- **Git e GitHub** — controle de versão e hospedagem do código.

## Funcionalidades

- [x] Criação de tarefas.
- [x] Remoção de tarefas.
- [x] Edição de título e descrição.
- [x] Consulta de tarefas por identificador.
- [x] Atualização do progresso das tarefas.
- [x] Cancelamento de tarefas.
- [x] Filtragem de tarefas por status.
- [x] Sistema inicial de logging e classificação de erros.

### Status das tarefas

As tarefas possuem os seguintes estados:

| Status | Descrição |
|---|---|
| `TO_DO` | Tarefa pendente. |
| `IN_PROGRESS` | Tarefa em andamento. |
| `CONCLUDED` | Tarefa concluída. |
| `CANCELLED` | Tarefa cancelada. |

## Estrutura do projeto

O projeto utiliza uma organização modular, com bibliotecas separadas por responsabilidade.

```text
TaskManager/
├── src/
│   ├── task/
│   │   ├── include/
│   │   ├── CMakeLists.txt
│   │   └── ...
│   ├── utils/
│   │   ├── include/
│   │   ├── CMakeLists.txt
│   │   └── ...
│   ├── CMakeLists.txt
│   └── main.cpp
├── data/
├── build/
├── CMakeLists.txt
└── CMakePresets.json
```

## Compilação

É necessário ter o CMake e um compilador C++20 instalados.

Na raiz do projeto, execute:

```bash
cmake -S . -B build
```

Em seguida, compile:

```bash
cmake --build build
```

## Próximos passos

O projeto ainda está em desenvolvimento. As próximas etapas planejadas são:

- [ ] **Validação de usuários:** implementar um mecanismo de autenticação ou validação de usuários para controlar o acesso ao sistema.
- [ ] **Geração de relatórios:** adicionar suporte à criação de relatórios no formato `.txt`, contendo informações sobre as tarefas e seus respectivos estados.
- [ ] **CI/CD:** configurar pipelines de integração usando yml e entrega contínua utilizando GitHub Actions, automatizando processos de build e validação do projeto.
- [ ] **Melhoria da CLI:** aprimorar a interface de linha de comando, tornando a navegação e a interação com as funcionalidades mais intuitivas.

## Objetivo de desenvolvimento

Além de sua finalidade prática, o TaskManager é um projeto de aprendizado voltado ao aprofundamento em C++, arquitetura de software, modularização, gerenciamento de memória e ferramentas de build.

O projeto tem intenção de ser escalável para servir de estudo em C++ junto de CMake, possui a intanção ser expandido de acordo de ideias novas que auxiliem no aprendizado da linguagem.