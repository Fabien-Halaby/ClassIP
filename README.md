Ces programme est utilisés pour connaitre les classes d'une addresse IP.
UTILISATION:
    - classe.c est un programme sous console.
    Vous pouvez utiliser les commandes suivants pour l'utiliser si vous avez déjà installé le compilateur: 
        $ gcc -o classe classe.c
        $ ./classe
    - classe_web.html et classe_web.c sont des programmes sur votre navigateur.
    Vous pouvez utiliser les commandes suivants pour l'utiliser si vous avez déjà installé appache:
        $ sudo mv classe_web.html /var/www/html/
        $ gcc -o classe_web.cgi classe_web.c
        $ sudo mv classe_web.cgi /usr/lib/cgi-bin/
    Puis vous pouvez taper directement sur votre navigateur préféré :
        http://localhost/classe_web.html
