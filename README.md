# OpenGL_s3
Projet C++ / OpenGL réalisé dans le cadre du s3 de l'IMAC.

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

Lancer le jeu :
`./PROJECT/tronple_run`

Ensuite, possibilité de générer la documentation. Toujours dans le répertoire build : 
`make html`

Tester les fuites mémoires avec valgrind : 
`valgrind --leak-check=yes ./PROJECT/tronple_run`
