# OpenGL_s3
Projet OpenGL réalisé dans le cadre du s3 de l'IMAC avec Noélie Bravo et Hédi Hamadache.

## Procédure pour lancer le jeu (Linux)
Il faut en premier lieu s’assurer d’avoir les bibliothèques OpenGL et SDL installées sur sa machine.

se déplacer dans le répertoire "tronple_run" du jeu :
`cd tronple_run`

Créer un répertoire "build" et s'y placer :
`mkdir build`
`cd build`

Compiler :
`cmake ..`
`make`

Lancer le main :
`./PROJECT/PROJECT_main`

Possibilité ensuite de générer la documentation. Toujours dans le répertoire build : 
`make html`