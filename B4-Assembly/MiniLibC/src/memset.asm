BITS 64

SECTION .text
GLOBAL memset

memset:
    MOV RAX, RDI ; je fais une copie de mon pointer dans RAX
    XOR RCX, RCX ; je set mon compteur à 0
    JMP _loop ; je démarre ma loop

_loop:
    CMP RCX, RDX ; si ma boucle atteint sa limite j'exit
    JE _exit
    MOV BYTE [RDI], SIL ; sinon je modifie la déréférence de RDI par le char passé en paramètre
    INC RDI ; j'incrémente mon pointeur
    INC RCX ; j'incrémente ma boucle
    JMP _loop ; je relance ma loop

_exit:
    RET ; je return mon pointeur stocké dans RAX
