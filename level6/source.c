#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    //    0x0804847c <+0>:	push   ebp
    //    0x0804847d <+1>:	mov    ebp,esp
    //    0x0804847f <+3>:	and    esp,0xfffffff0

    char *buf1;
    char *buf2;
    void *ptr;
    //    0x08048482 <+6>:	sub    esp,0x20

    buf1 = malloc(64);
    //    0x08048485 <+9>:	mov    DWORD PTR [esp],0x40
    //    0x0804848c <+16>:	call   0x8048350 <malloc@plt>
    //    0x08048491 <+21>:	mov    DWORD PTR [esp+0x1c],eax

    buf2 = malloc(4);
    //    0x08048495 <+25>:	mov    DWORD PTR [esp],0x4
    //    0x0804849c <+32>:	call   0x8048350 <malloc@plt>
    //    0x080484a1 <+37>:	mov    DWORD PTR [esp+0x18],eax

    ptr = 0x8048468; // m address
    //    0x080484a5 <+41>:	mov    edx,0x8048468                // store m address into edx
    //    0x080484aa <+46>:	mov    eax,DWORD PTR [esp+0x18]     // store buf2 address into eax
    //    0x080484ae <+50>:	mov    DWORD PTR [eax],edx          // store m address into ADDRESS CONTAINED IN EAX ==> Into buf2
    //    0x080484b0 <+52>:	mov    eax,DWORD PTR [ebp+0xc]      // take value 12 bytes under main stack frame into eax (address argv1 ?)
    //    0x080484b3 <+55>:	add    eax,0x4                      // adds 4 to eax value => (0xc + 0x4 = ebp + 0xf ?)
    //    0x080484b6 <+58>:	mov    eax,DWORD PTR [eax]          // stores the value pointed by EAX stored address into EAX (dereferencing pointer)
    //    0x080484b8 <+60>:	mov    edx,eax                      // store eax into edx
    //    0x080484ba <+62>:	mov    eax,DWORD PTR [esp+0x1c]     // store buf1 address into eax

    strcpy(buf1, argv[1]); // not sure
    //    0x080484be <+66>:	mov    DWORD PTR [esp+0x4],edx
    //    0x080484c2 <+70>:	mov    DWORD PTR [esp],eax
    //    0x080484c5 <+73>:	call   0x8048340 <strcpy@plt>
    //    0x080484ca <+78>:	mov    eax,DWORD PTR [esp+0x18]     //  loads buf2 (containing m address) into eax
    //    0x080484ce <+82>:	mov    eax,DWORD PTR [eax]          //  dereferences m address into eax
    //    0x080484d0 <+84>:	call   eax                          //  calls m
    //    0x080484d2 <+86>:	leave
    //    0x080484d3 <+87>:	ret
}

void n(void)
{
    system("/bin/cat /home/user/level7/.pass");
    //    0x08048454 <+0>:	push   ebp
    //    0x08048455 <+1>:	mov    ebp,esp
    //    0x08048457 <+3>:	sub    esp,0x18
    //    0x0804845a <+6>:	mov    DWORD PTR [esp],0x80485b0
    //    0x08048461 <+13>:	call   0x8048370 <system@plt>
    //    0x08048466 <+18>:	leave
    //    0x08048467 <+19>:	ret
}

void m(void)
{
    puts("Nope");
    //    0x08048468 <+0>:	push   ebp
    //    0x08048469 <+1>:	mov    ebp,esp
    //    0x0804846b <+3>:	sub    esp,0x18
    //    0x0804846e <+6>:	mov    DWORD PTR [esp],0x80485d1
    //    0x08048475 <+13>:	call   0x8048360 <puts@plt>
    //    0x0804847a <+18>:	leave
    //    0x0804847b <+19>:	ret
}