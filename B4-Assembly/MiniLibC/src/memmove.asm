BITS 64

SECTION .text
GLOBAL memmove

memmove:
    XOR RCX, RCX ; j'initialise mon compteur à 0
    MOV RAX, RDI ; j'attribue à ma valeur de retour, le pointeur vers la dest
    CMP RDX, 0
    JE _exit
    CMP RDI, RSI ; je vérifie si RDI et RSI ne pointe pas vers la même case mémoire
    JE _exit ; si c'est le cas je retourne simplement ma dest
    JG _set_copy_back ; si ma destination est avant ma source, je vais inverser le sens de copie
    JMP _loop ; sinon je start ma copie simplement

_set_copy_back:
    MOV RCX, RDX
    JMP _loop_back

_loop:
    CMP RCX, RDX ; je vérifie si mon compteur est égal au nombre de char que je veux copier
    JE _exit ; dans ce cas je retourne mon pointeur vers dest
    MOV R8B, [RSI + RCX] ; sinon je charge le char de ma source dans AL
    MOV [RDI + RCX], R8B ; puis je copie la valeur de AL dans ma destination
    INC RCX ; j'incrémente mon compteur de loop
    JMP _loop ; je relance ma loop

_loop_back:
    CMP RCX, 0
    JE _exit
    MOV R8B, [RSI + RCX - 1] ; sinon je charge le char de ma source dans AL
    MOV [RDI + RCX - 1], R8B ; puis je copie la valeur de AL dans ma destination
    DEC RCX ; j'incrémente mon compteur de loop
    JMP _loop_back ; je relance ma loop

_exit:
    RET ; je retourne mon pointeur stocké dans RAX
