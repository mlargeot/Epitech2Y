BITS 64

SECTION .text
GLOBAL strrchr

strrchr:
    XOR RAX, RAX ; j'init RAX à 0
    JMP _loop ; le lance ma loop (_loop pour eviter les erreurs de compilation)


_loop:
    CMP BYTE [RDI], SIL ; je regarde si mon char est celui attendu
    JE _change_pointer ; dans ce cas je vais changer la valeur du pointeur dans RDX
    CMP BYTE [RDI], 0 ; je regarde si la fin de ma string est atteinte
    JE _exit ; dans ce cas j'exit mon programme
    INC RDI ; sinon j'incrémente mon pointeur
    JMP _loop ; je relance ma boucle

_change_pointer:
    MOV RAX, RDI ; je set la valeur de RAX au pointeur RDI
    INC RDI ; j'incrémente RDI pour éviter de faire une loop sans fin
    JMP _loop ; je retourne dans ma loop

_exit:
    RET ; je return RAX
