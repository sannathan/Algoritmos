# Atalhos do VS Code (Linux)

Este documento lista atalhos úteis do Visual Studio Code para Linux (padrões de fábrica), organizados por categoria. Caso você possua um arquivo `keybindings.json` personalizado, veja ao final como atualizar este documento automaticamente.

Observação: Em teclados ABNT2, a tecla Ctrl é `Ctrl`, Alt é `Alt` e tecla Super é `Super`.

## Edição
- Ctrl + X — Recortar linha
- Ctrl + C — Copiar linha
- Ctrl + V — Colar
- Ctrl + Shift + K — Excluir linha
- Ctrl + Enter — Inserir linha abaixo
- Ctrl + Shift + Enter — Inserir linha acima
- Alt + Seta para cima/baixo — Mover linha para cima/baixo
- Shift + Alt + Seta para cima/baixo — Duplicar linha
- Ctrl + Shift + \ — Ir para colchete correspondente
- Ctrl + ] / Ctrl + [ — Recuar/Desrecuar linha
- Ctrl + / — Alternar comentário de linha
- Shift + Alt + A — Alternar comentário de bloco
- Alt + Z — Quebra de linha automática (toggle)
- Ctrl + F — Localizar
- Ctrl + H — Substituir
- F3 / Shift + F3 — Localizar próximo/anterior
- Alt + Enter — Selecionar todas as ocorrências da busca
- Ctrl + D — Adicionar seleção da próxima ocorrência
- Ctrl + U — Desfazer última seleção do cursor
- Ctrl + L — Selecionar linha atual
- Ctrl + Shift + L — Selecionar todas as correspondências da seleção
- Ctrl + Shift + Alt + setas — Seleções de coluna (modo caixa)
- Ctrl + Espaço — Sugerir/IntelliSense
- Ctrl + . — Correção rápida/ações de código
- F2 — Renomear símbolo
- Ctrl + K, Ctrl + X — Remover espaços finais

## Navegação de código
- Ctrl + P — Abrir arquivo rápido (Go to File)
- Ctrl + G — Ir para linha
- Ctrl + T — Ir para símbolo global
- Ctrl + Shift + O — Ir para símbolo no arquivo
- F12 — Ir para definição
- Alt + F12 — Espiar definição (Peek)
- Ctrl + K, F12 — Abrir definição ao lado
- Ctrl + Clique — Ir para definição
- Shift + F12 — Encontrar referências
- Ctrl + K, Ctrl + I — Mostrar dica (hover)
- Ctrl + Tab — Alternar entre editores recentes
- Ctrl + B — Alternar barra lateral

## Multi-cursor e seleção
- Alt + Clique — Inserir cursor
- Ctrl + Alt + setas — Cursor acima/abaixo
- Shift + Alt + I — Inserir cursor no fim de cada linha selecionada
- Ctrl + Shift + Alt + setas — Seleção em caixa (coluna)

## Layout do editor e abas
- Ctrl + \ — Dividir editor (vertical)
- Ctrl + 1 / 2 / 3 — Focar grupo de editor 1/2/3
- Ctrl + K, Seta para esquerda/direita — Focar grupo anterior/próximo
- Ctrl + K, Ctrl + ←/→ — Mover arquivo para grupo anterior/próximo
- Ctrl + W — Fechar editor atual
- Ctrl + K, W — Fechar todos os editores
- Ctrl + Shift + T — Reabrir editor fechado
- Ctrl + K, Z — Modo Zen

## Terminal integrado
- Ctrl + ` — Mostrar/ocultar terminal
- Ctrl + Shift + ` — Novo terminal
- Ctrl + C — Enviar interrupção (no terminal)
- Ctrl + ↑ / ↓ — Rolagem
- Ctrl + K — Limpar terminal
- Ctrl + Shift + C — Copiar do terminal
- Ctrl + Shift + V — Colar no terminal

## Depuração (Debug)
- F9 — Alternar breakpoint
- F5 — Iniciar/continuar depuração
- Shift + F5 — Parar
- F11 — Entrar (Step Into)
- Shift + F11 — Sair (Step Out)
- F10 — Avançar (Step Over)
- Ctrl + K, Ctrl + I — Mostrar hover durante debug

## Git e controle de versão
- Ctrl + Shift + G — Exibir Source Control
- Ctrl + Enter (no SCM) — Confirmar commit
- Ctrl + Shift + P — Abrir Paleta de Comandos (para ações Git adicionais)

## Paleta de comandos e interface
- Ctrl + Shift + P — Paleta de Comandos
- F1 — Paleta de Comandos (alternativa)
- Ctrl + K, Ctrl + S — Abrir Atalhos de Teclado
- Ctrl + , — Configurações
- Ctrl + J — Mostrar/ocultar painel (terminal/saída/problems)
- Ctrl + Shift + U — Saída (Output)
- Ctrl + Shift + M — Problemas (Problems)
- Ctrl + Shift + Y — Console de Depuração
- Ctrl + B — Alternar barra lateral
- Ctrl + Shift + E — Explorador
- Ctrl + Shift + F — Busca Global
- Ctrl + Shift + D — Executar e Depurar
- Ctrl + Shift + X — Extensões

## Como atualizar este arquivo a partir do keybindings.json

Caso você tenha atalhos personalizados:
1. Abra a Paleta de Comandos (Ctrl + Shift + P) e execute “Preferences: Open Keyboard Shortcuts (JSON)”.
2. Copie o conteúdo do seu `keybindings.json` e adicione-o ao arquivo `.vscode/keybindings.json` neste repositório (ou compartilhe o JSON comigo).
3. Com o `keybindings.json` disponível no projeto, posso regenerar este `ATALHOS.md` refletindo seus atalhos exatos, organizados por categoria e com descrições.

Dica: Você também pode exportar as configurações via “Preferences: Open Keyboard Shortcuts” e usar o ícone de abrir em JSON no canto superior direito.
