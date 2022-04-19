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

  BIGNUM *p, *q, *n, *phi, *e, *d, *m, *c, *res, *s;
  BIGNUM *new_m, *p_minus_one, *q_minus_one;
  p = BN_new(); q = BN_new(); n = BN_new(); e = BN_new();
  d = BN_new(); m = BN_new(); c = BN_new(); s = BN_new();
  res = BN_new(); phi = BN_new(); new_m = BN_new(); 
  p_minus_one = BN_new(); q_minus_one = BN_new(); 

  // Set the public key exponent e
  BN_dec2bn(&e, "65537");

  // Generate random p and q.
  //BN_generate_prime_ex(p, NBITS, 1, NULL, NULL, NULL); 
  //BN_generate_prime_ex(q, NBITS, 1, NULL, NULL, NULL);
  //BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
  //BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
  //BN_sub(p_minus_one, p, BN_value_one());     // Compute p-1
  //BN_sub(q_minus_one, q, BN_value_one());     // Compute q-1
  //BN_mul(n, p, q, ctx);                       // Compute n=pq
  //BN_mul(phi, p_minus_one, q_minus_one, ctx); // Compute (*@$\phi(n)$@*)
  BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
  BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

  printBN("n:", n);
  printBN("Public key:", e);

  // Check whether e and (*@$\phi(n)$@*) are relatively prime.  
  //BN_gcd(res, phi, e, ctx);
  //if (!BN_is_one(res)) { 
     //exit(0);  // They are not relatively prime, try it again.
  //}

  // Compute the private key exponent d, s.t. ed mod phi(n) = 1
  //BN_mod_inverse(d, e, phi, ctx);                         
  //printBN("Private key:", d);

  // Encryption: calculate m^e mod n
  BN_hex2bn(&s, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");    
  //BN_mod_exp(c, m, e, n, ctx);
  printBN("Digital signature:", s);

  // Digital signature: calculate m^d mod n
  BN_mod_exp(new_m, s, e, n, ctx);
  printBN("Varified message:", new_m);

  // Clear the sensitive data from the memory             
  BN_clear_free(p); BN_clear_free(q); BN_clear_free(d); 
  BN_clear_free(phi); BN_clear_free(m); BN_clear_free(new_m); 
  BN_clear_free(c); BN_clear_free(res); BN_clear_free(s);
  BN_clear_free(p_minus_one); BN_clear_free(q_minus_one); 

  return 0;
}

