BITS 64

SECTION .text
GLOBAL memmove

memmove:
    XOR RCX, RCX ; j'initialise mon compteur à 0
    MOV RAX, RDI ; j'attribue à ma valeur de retour, le pointeur vers la dest
    CMP RDI, RSI ; je vérifie si RDI et RSI ne pointe pas vers la même case mémoire
    JE _exit ; si c'est le cas je retourne simplement ma dest 
    CMP RDI, RSI ; je compare RSI et RDI afin de determiner le sens de ma copie pour gerer l'overlap
    JL _set_copy_back ; si ma destination est avant ma source, je vais inverser le sens de copie
    JMP _loop ; sinon je start ma copie simplement

_set_copy_back:
    ADD RSI, RDX ; je déplace mes pointeurs vers la fin de mes stirng
    ADD RDI, RDX
    DEC RSI ; je décrémente mes pointeurs afin d'être sur le dernier élément de mes stirng (1 trop loin sinon)
    DEC RDI
    JMP _loop ; je start ma copie

_loop:
    CMP RCX, RDX ; je vérifie si mon compteur est égal au nombre de char que je veux copier
    JE _exit ; dans ce cas je retourne mon pointeur vers dest
    MOV AL, [RSI] ; sinon je charge le char de ma source dans AL
    MOV [RDI], AL ; puis je copie la valeur de AL dans ma destination
    CMP RAX, RDI ; je vérifie mon sens de copie en comparant mon pointeur actuel de dest à son pointeur de base
    JL _dec ; si je suis dans le cas ou ma copie est dans le sens inverse dans ce cas je décrémente mes pointeurs
    INC RSI ; sinon je les incrémente
    INC RDI
    INC RCX ; j'incrémente mon compteur de loop
    JMP _loop ; je relance ma loop

_dec:
    DEC RDI ; je décrémente mes pointeurs
    DEC RSI
    INC RCX ; j'incrémente mon compteur de loop
    JMP _loop ; je relance ma loop

_exit:
    RET ; je retourne mon pointeur stocké dans RAX
