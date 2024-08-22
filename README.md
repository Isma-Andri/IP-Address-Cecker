# IP Checker

`IP Checker` :script CGI écrit en C qui permet de vérifier la validité d'une adresse IPv4 et de déterminer sa classe (A, B, C, D ou E). Deux fichiers sont fournis : `ipchecker.c` pour le script CGI et `ipchecker.html` pour la page HTML.

## Compilation

Pour compiler et exécuter ce script CGI, mila:

- Un serveur web compatible avec CGI (comme Apache).
- Un compilateur C (comme `gcc`).
- L'accès au répertoire CGI de votre serveur web (`/usr/lib/cgi-bin/` ou similaire).

## Compilation

Pour compiler `ipchecker.c`, utilisez le compilateur GCC comme suit :

```bash
gcc -o ipchecker.cgi ipchecker.c
