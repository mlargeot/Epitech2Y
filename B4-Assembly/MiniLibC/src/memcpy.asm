BITS 64

SECTION .text
GLOBAL memcpy

memcpy:
    XOR RCX, RCX ; j'init mon compteur à 0
    MOV RAX, RDI ; je set ma valeur de retour qui sera le pointeur vers dest(RDI)
    JMP .loop ; je lance ma boucle

.loop:
    CMP RCX, RDX ; je vérifie l'etait de ma boucle par rapport a la limite en paramètre (RDX)
    JE _exit ; j'exit dans le cas ou j'ai tout copié
    MOV BL, BYTE [RSI] ; je stock dans bl la valeur du premier char de la source (RSI)
    MOV BYTE [RDI], BL ; je set la valeur du char de la dest (RDI) à celle de la source (RSI)
    INC RDI ; j'incrémente mes pointeurs et mon compteur
    INC RSI
    INC RCX
    JMP .loop ; je relance ma boucle

_exit:
    RET ; je return le pointeur vers dest stocké dans RAX