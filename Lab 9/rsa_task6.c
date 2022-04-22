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

  BIGNUM *n, *e, *s, *new_m;
  n = BN_new(); e = BN_new();
  s = BN_new(); new_m = BN_new(); 

  // Set the public key exponent e
  BN_dec2bn(&e, "65537");

  // Input modulus
  BN_hex2bn(&n, "D753A40451F899A616484B6727AA9349D039ED0CB0B00087F1672886858C8E63DABCB14038E2D3F5ECA50518B83D3EC5991732EC188CFAF10CA6642185CB071034B052882B1F689BD2B18F12B0B3D2E7881F1FEF387754535F80793F2E1AAAA81E4B2B0DABB763B935B77D14BC594BDF514AD2A1E20CE29082876AAEEAD764D69855E8FDAF1A506C54BC11F2FD4AF29DBB7F0EF4D5BE8E16891255D8C07134EEF6DC2DECC48725868DD821E4B04D0C89DC392617DDF6D79485D80421709D6F6FFF5CBA19E145CB5657287E1C0D4157AAB7B827BBB1E4FA2AEF2123751AAD2D9B86358C9C77B573ADD8942DE4F30C9DEEC14E627E17C0719E2CDEF1F910281933");

  printBN("n:", n);
  printBN("Public key:", e);

  // Input digital signature
  BN_hex2bn(&s, "3eeabecd2a9832f1224eda65c7bfaa2a1d1ac54ac27c088a7e73bcfce5f0bc3ff6b0ab7c2d07f2e7a9f17de818dd00d0d9bc0e374a972f1147195d38cd4bfa12d7e3841aec0e2a576dd3d28529e8a9693bced5780c8e1d13d87ee0fc4decb1e9e9b06579bdb1e3cc3b345ef92fea751e90b91273dca259427c3284c3f7d8680e10c32477b50a4754594b6d82cf99efe9ebd8df63734a28a16669e698cc51fadefb9825f28ec6c9e017aeed169ef906477da20db5ecc5513fcb5af9ba37913a5c002f7701103ab6aee50d21c0503281e0c5fdb4cdd0153bdec1d99d90ddc06a8f95594c2ab4a1ca32e04dd2a4ea4828c2ae168ddf53cb94638e61b70c79fd0b5f");    
  
  printBN("Digital signature:", s);

  // Verification: calculate s^e mod n
  BN_mod_exp(new_m, s, e, n, ctx);
  printBN("Verified signature:", new_m);

  // Clear the sensitive data from the memory             
  BN_clear_free(new_m); BN_clear_free(s);

  return 0;
}

