BITS 64

SECTION .text
GLOBAL strpbrk

strpbrk:
    MOV R8, RSI ; je set une copie de mon pointeur de ma liste de verification
    JMP _loop

_loop:
    MOV AL, BYTE [RDI] ; je charge le caractere de RDI dans AL
    CMP AL, 0 ; si j'arrive au null pointer je retourne null
    JE _exit_null
    JMP _handle_char ; je lance la boucle de verification du char

_handle_char:
    CMP BYTE [RSI], AL ; je compare mon char de ma string avec le premier char de ma liste de searched
    JE _exit ; si le char appartient à mes searched j'exit mon programme
    CMP BYTE [RSI], 0 ; si mon char atteint la fin de la liste des searched
    JE _reload ; je relance ma loop initiale en modifiant les valeurs
    INC RSI ; sinon je me déplace dans ma liste de reject
    JMP _handle_char ; et je relance ma verification

_reload:
    MOV RSI, R8; je reset la valeur de mon pointeur à sa valuer d'origine
    INC RDI ; je me déplace dans ma string à vérifier
    JMP _loop ; je relance ma loop d'origine

_exit:
    MOV RAX, RDI ; je set RAX au pointeur à partir duquel le char à été toruvé
    RET ; je return RAX

_exit_null:
    MOV RAX, 0 ; je set RAX à null
    RET ; je return RAX
