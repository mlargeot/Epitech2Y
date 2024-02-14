BITS 64

SECTION .text
GLOBAL strncmp

strncmp:

    XOR RCX, RCX
    JMP .loop ; je démarre ma boucle

.loop:
    CMP RCX, RDX ; je regarde si mon compteur est situé à ma limite
    JE _exit ; j'exit si mon compteur atteind ma limite
    MOV AL, [RDI] ; je charge le caractère de RDI dans AL
    MOV BL, [RSI] ; je charge le caractère de RSI dans BL
    CMP AL, BL ; je compare les caractères
    JNE _exit ; si ils ne sont pas égaux j'exit
    CMP BYTE [RDI], 0 ; dans le cas ou ils sont égaux et leur valeur est au null pointeur j'exit
    JE _exit
    INC RCX ; j'incrémente ma limite
    INC RDI ; sinon s'ils sont égaux et différents de 0 j'incrémente mes pointeur et je relance ma loop
    INC RSI
    JMP .loop

_exit:
    CMP RDX, 0 ; dans le cas ou je cherche à comparer 0 elm j'exit 0
    JE _exit_null
    MOVZX RAX, AL ; je set RAX à la valeur de char s1 
    MOVZX RBX, BL ; je set RBX à la valeur de char s2
    SUB RAX, RBX ; je soustrait les deux valeur pour obtenir la diff
    RET ; je retourne RAX

_exit_null:
    XOR RAX, RAX
    RET