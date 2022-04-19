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

  BIGNUM *n, *e, *s;
  BIGNUM *new_m;
  n = BN_new(); e = BN_new();
  s = BN_new();
  new_m = BN_new();

  // Set the public key exponent e
  BN_dec2bn(&e, "65537");

  BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
  BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

  printBN("n:", n);
  printBN("Public key:", e);

  BN_hex2bn(&s, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");    
  printBN("Digital signature:", s);

  // Verified message: calculate s^e mod n
  BN_mod_exp(new_m, s, e, n, ctx);
  printBN("Varified message:", new_m);

  // Clear the sensitive data from the memory              
  BN_clear_free(new_m); 
  BN_clear_free(s); 

  return 0;
}

