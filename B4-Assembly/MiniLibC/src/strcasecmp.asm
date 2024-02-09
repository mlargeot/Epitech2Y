BITS 64

SECTION .text
GLOBAL strcasecmp

strcasecmp:

    JMP _loop ; je démarre ma boucle

_loop:
    MOV AL, [RDI] ; je charge le caractère de RDI dans AL
    CMP AL, 'a' ; je vérifie ou le AL est potentiellement une lowercase
    JGE _handle_lower_1 ; si oui j'handle AL (JUMP IF GREATER OR EQUAL)
    MOV BL, [RSI] ; sinon je fais le même processus pour BL qui récupère le byte de RSI
    CMP BL, 'a'
    JGE _handle_lower_2
    JMP _compare ; si ni AL et BL sont potentiellement des lowercases je compare directement

_handle_lower_1:
    CMP AL, 'z' ; je vérifie si AL est bel et bien une lower case
    JLE _set_upper_1 ; si c'est le cas je le transforme en uppercase (JUMP IF LOWER OR EQUAL)
    MOV BL, [RSI] ; sinon je reprend le processus du début pour BL
    CMP BL, 'a'
    JGE _handle_lower_2
    JMP _compare ; je compare si BL n'est pas une lowercase potentielle

_set_upper_1:
    SUB AL, 32 ; je passe AL en uppercase
    MOV BL, [RSI] ; je reprend le processus pour BL
    CMP BL, 'a'
    JGE _handle_lower_2
    JMP _compare

_handle_lower_2:
    CMP BL, 'z' ; même processus que pour AL avec BL
    JLE _set_upper_2
    JMP _compare

_set_upper_2:
    SUB BL, 32 ; je passe BL en uppercase
    JMP _compare

_compare:
    CMP AL, BL ; je compare les valeurs de AL et BL
    JNE _exit ; dans le cas ou elles diffèrent j'exit
    CMP BYTE [RDI], 0 ; si elles sont égales, je vérifie que je ne suis pas au bout de ma string
    JE _exit ; si c'est le cas j'exit
    INC RDI ; sinon j'incrémente mes pointeurs
    INC RSI
    JMP _loop ; je relance ma loop

_exit:
    MOVZX RAX, AL ; je set RAX à la valeur de char s1 
    MOVZX RBX, BL ; je set RBX à la valeur de char s2
    SUB RAX, RBX ; je soustrait les deux valeur pour obtenir la diff
    RET ; je retourne RAX
