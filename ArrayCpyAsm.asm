; array_cpy_asm procedure				(ArrayCpyAsm.asm)

.586
.model flat, C
array_cpy_asm Proto, sourcePtr:Ptr DWord, destPtr:Ptr DWord, count:DWord

.code
;------------------------------------------------------------------------------
; Copies content of a source 32-bit array to dest 32-bit array.
; Receives: sourcePtr - pointer to the source 32-bit array,
;			destPtr - pointer to the dest 32-bit array,
;			count - the lenght of source and dest array.
; Returns: Nothing.
;------------------------------------------------------------------------------
array_cpy_asm Proc Uses esi edi ecx,
					sourcePtr:Ptr DWord,
					destPtr:Ptr DWord,
					count:DWord
	mov esi,sourcePtr
	mov edi,destPtr
	mov ecx,count
	cld
	rep movsd

	ret
array_cpy_asm EndP
End
