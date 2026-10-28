extern "C" void kernelMain() 
{
    volatile unsigned char* vga = (volatile unsigned char*)0xB8000;

    const char* str = "TantrumsOS";
    const char* empty = "";

	for (int i = 0; i != 4000; i++) 
	{
        vga[i * 2]     = empty[0]; 
        vga[i * 2 + 1] = 0x0F;   
    }
	
    for (int i = 0; str[i] != '\0'; i++) 
	{
        vga[i * 2]     = str[i]; 
        vga[i * 2 + 1] = 0x0F;   
    }

    while (true) {}
}