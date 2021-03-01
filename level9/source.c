
void *_Znwj(int c)
{
    void *ptr;
    //    0xf7e60740 <+0>:	endbr32
    //    0xf7e60744 <+4>:	push   esi
    //    0xf7e60745 <+5>:	mov    esi,0x1
    //    0xf7e6074a <+10>:	push   ebx
    //    0xf7e6074b <+11>:	call   0xf7e5c2d0
    //    0xf7e60750 <+16>:	add    ebx,0x14d8b0
    //    0xf7e60756 <+22>:	sub    esp,0x4
    //    0xf7e60759 <+25>:	mov    eax,DWORD PTR [esp+0x10]
    //    0xf7e6075d <+29>:	test   eax,eax
    //    0xf7e6075f <+31>:	cmovne esi,eax
    //    0xf7e60762 <+34>:	sub    esp,0xc
    //    0xf7e60765 <+37>:	push   esi

    ptr = malloc(c);
    //    0xf7e60766 <+38>:	call   0xf7e4fcc0 <malloc@plt>
    //    0xf7e6076b <+43>:	add    esp,0x10

    if (*ptr == 0)
    //    0xf7e6076e <+46>:	test   eax,eax
    //    0xf7e60770 <+48>:	je     0xf7e60778 <_Znwj+56>
    {
        return (ptr);
        //    0xf7e60772 <+50>:	add    esp,0x4
        //    0xf7e60775 <+53>:	pop    ebx
        //    0xf7e60776 <+54>:	pop    esi
        //    0xf7e60777 <+55>:	ret
    }

    ? ()
    //    0xf7e60778 <+56>:	call   0xf7e4e030 <_ZSt15get_new_handlerv@plt>
    //    0xf7e6077d <+61>:	test   eax,eax
    //    0xf7e6077f <+63>:	je     0xf7e5169f
    //    0xf7e60785 <+69>:	call   eax                              // exploit here ?
    //    0xf7e60787 <+71>:	jmp    0xf7e60762 <_Znwj+34>
}

// add nb at the end of ptr
void _ZN1NC2Ei(void *ptr, int nb)
{
    //    0x080486f6 <+0>:	push   ebp
    //    0x080486f7 <+1>:	mov    ebp,esp
    //    0x080486f9 <+3>:	mov    eax,DWORD PTR [ebp+0x8]
    //    0x080486fc <+6>:	mov    DWORD PTR [eax],0x8048848
    //    0x08048702 <+12>:	mov    eax,DWORD PTR [ebp+0x8]
    //    0x08048705 <+15>:	mov    edx,DWORD PTR [ebp+0xc]
    //    0x08048708 <+18>:	mov    DWORD PTR [eax+0x68],edx
    //    0x0804870b <+21>:	pop    ebp
    //    0x0804870c <+22>:	ret
}

void_ZN1N13setAnnotationEPc(void *buf1, char *argv1)
{
    //    0x0804870e <+0>:	push   ebp
    //    0x0804870f <+1>:	mov    ebp,esp
    //    0x08048711 <+3>:	sub    esp,0x18
    //    0x08048714 <+6>:	mov    eax,DWORD PTR [ebp+0xc]

    len = strlen(argv1);
    //    0x08048717 <+9>:	mov    DWORD PTR [esp],eax
    //    0x0804871a <+12>:	call   0x8048520 <strlen@plt>

    //    0x0804871f <+17>:	mov    edx,DWORD PTR [ebp+0x8]
    //    0x08048722 <+20>:	add    edx,0x4
    //    0x08048725 <+23>:	mov    DWORD PTR [esp+0x8],eax
    //    0x08048729 <+27>:	mov    eax,DWORD PTR [ebp+0xc]

    memcpy(buf1 + 4, argv1, len);
    //    0x0804872c <+30>:	mov    DWORD PTR [esp+0x4],eax
    //    0x08048730 <+34>:	mov    DWORD PTR [esp],edx
    //    0x08048733 <+37>:	call   0x8048510 <memcpy@plt>
    //    0x08048738 <+42>:	leave
    //    0x08048739 <+43>:	ret
}

int main(void)
{
    //    0x080485f4 <+0>:	push   ebp
    //    0x080485f5 <+1>:	mov    ebp,esp
    //    0x080485f7 <+3>:	push   ebx
    //    0x080485f8 <+4>:	and    esp,0xfffffff0

    void *ptr;
    //    0x080485fb <+7>:	sub    esp,0x20
    //    0x080485fe <+10>:	cmp    DWORD PTR [ebp+0x8],0x1
    //    0x08048602 <+14>:	jg     0x8048610 <main+28>

    exit(1);
    //    0x08048604 <+16>:	mov    DWORD PTR [esp],0x1
    //    0x0804860b <+23>:	call   0x80484f0 <_exit@plt>

    ptr = _Znwj(108);
    //    0x08048610 <+28>:	mov    DWORD PTR [esp],0x6c
    //    0x08048617 <+35>:	call   0x8048530 <_Znwj@plt>
    //    0x0804861c <+40>:	mov    ebx,eax

    _ZN1NC2Ei(ptr, 5);
    //    0x0804861e <+42>:	mov    DWORD PTR [esp+0x4],0x5
    //    0x08048626 <+50>:	mov    DWORD PTR [esp],ebx
    //    0x08048629 <+53>:	call   0x80486f6 <_ZN1NC2Ei>

    _Znwj(108);
    //    0x0804862e <+58>:	mov    DWORD PTR [esp+0x1c],ebx
    //    0x08048632 <+62>:	mov    DWORD PTR [esp],0x6c
    //    0x08048639 <+69>:	call   0x8048530 <_Znwj@plt>
    //    0x0804863e <+74>:	mov    ebx,eax

    _ZN1NC2Ei(res, 6);
    //    0x08048640 <+76>:	mov    DWORD PTR [esp+0x4],0x6
    //    0x08048648 <+84>:	mov    DWORD PTR [esp],ebx
    //    0x0804864b <+87>:	call   0x80486f6 <_ZN1NC2Ei>

    //    0x08048650 <+92>:	mov    DWORD PTR [esp+0x18],ebx
    //    0x08048654 <+96>:	mov    eax,DWORD PTR [esp+0x1c]
    //    0x08048658 <+100>:	mov    DWORD PTR [esp+0x14],eax
    //    0x0804865c <+104>:	mov    eax,DWORD PTR [esp+0x18]
    //    0x08048660 <+108>:	mov    DWORD PTR [esp+0x10],eax
    //    0x08048664 <+112>:	mov    eax,DWORD PTR [ebp+0xc]
    //    0x08048667 <+115>:	add    eax,0x4
    //    0x0804866a <+118>:	mov    eax,DWORD PTR [eax]

    _ZN1N13setAnnotationEPc()
        //    0x0804866c <+120>:	mov    DWORD PTR [esp+0x4],eax
        //    0x08048670 <+124>:	mov    eax,DWORD PTR [esp+0x14]
        //    0x08048674 <+128>:	mov    DWORD PTR [esp],eax
        //    0x08048677 <+131>:	call   0x804870e <_ZN1N13setAnnotationEPc>

        //    0x0804867c <+136>:	mov    eax,DWORD PTR [esp+0x10]
        //    0x08048680 <+140>:	mov    eax,DWORD PTR [eax]
        //    0x08048682 <+142>:	mov    edx,DWORD PTR [eax]
        //    0x08048684 <+144>:	mov    eax,DWORD PTR [esp+0x14]

        ? (x, y)
    //    0x08048688 <+148>:	mov    DWORD PTR [esp+0x4],eax
    //    0x0804868c <+152>:	mov    eax,DWORD PTR [esp+0x10]
    //    0x08048690 <+156>:	mov    DWORD PTR [esp],eax
    //    0x08048693 <+159>:	call   edx
    //    0x08048695 <+161>:	mov    ebx,DWORD PTR [ebp-0x4]
    //    0x08048698 <+164>:	leave
    //    0x08048699 <+165>:	ret
}
