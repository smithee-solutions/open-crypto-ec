#if 0
int eac_crypto_digest_update
  (EAC_ENCODE_CONTEXT *ctx,
  EAC_ENCODE_OBJECT *digest,
  unsigned char *message,
  int msg_lth)
int eac_crypto_digest_finish
  (EAC_ENCODE_CONTEXT *ctx,
  EAC_ENCODE_OBJECT *digest_object,
  unsigned char *digest_raw,
  int *digest_lth)
#endif
/*
  eac crypto digest routines fased on ilvn/SHA256
*/


#include <SHA256.h>


#include <eac-encode.h>


#include <eac-crypto_open3.h>


int eac_crypto_digest_init
  (EAC_ENCODE_CONTEXT *ctx,
  EAC_ENCODE_OBJECT *digest)

{ /* eac_crypto_digest_init */

  int status;


  status = ST_OK;
  digest->internal = malloc(sizeof(OB_CRYPTO_CONTEXT_OPEN3));
  my_context = digest->internal;
  memset(my_context, 0, sizeof(*my_context));
  sha256_init(&(my_context->sha256_context));

  return(status);

} /* eac_crypto_digest_init */

