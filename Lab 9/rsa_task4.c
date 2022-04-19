#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 512 

void printBN(char *msg, BIGNUM * a)
{
   char * number_str = BN_bn2hex(a);
   printf("%s %s\n", msg, number_str);
   OPENSSL_free(number_str);
}

int main ()
{
  BN_CTX *ctx = BN_CTX_new();

  BIGNUM *n, *d, *m, *c;
  BIGNUM *new_m;
  n = BN_new();
  d = BN_new(); m = BN_new(); c = BN_new(); 
  new_m = BN_new(); 

  BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
  BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

  printBN("n:", n);                      
  printBN("Private key:", d);

  // Encryption: calculate m^e mod n
  BN_hex2bn(&m, "49206F776520796F752024393030302E");    
  printBN("M:", m);

  // Digital signature: calculate m^d mod n
  BN_mod_exp(new_m, m, d, n, ctx);
  printBN("Digital signature:", new_m);

  // Clear the sensitive data from the memory             
  BN_clear_free(d); 
  BN_clear_free(m); BN_clear_free(new_m); 

  return 0;
}

