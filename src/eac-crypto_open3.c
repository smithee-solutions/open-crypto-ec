/*
  eac crypto routines for EC based on micro-ecc
*/


#include <eac-encode.h>


#include <eac-crypto_open3.h>


// init key


// key_parameters of signature_info  show object is a sig alg, alg in parameters
// doc using it to extract oid for cyclone case

/*

  signature_info -
    if encoded buffer nonempty it is the DER of the sigalg, else
    if key_parameters[0] is nonzero it is the sigalg.
*/


int eac_crypto_verify_signature_ex
  (EAC_ENCODE_CONTEXT *ctx,
  EAC_ENCODE_OBJECT *signer_key,
  unsigned char *message,
  int msg_lth,
  EAC_ENCODE_OBJECT *signature,
  EAC_ENCODE_OBJECT *signature_info)

{ /* eac_crypto_verify_signature_ex */

  OB_CRYPTO_CONTEXT_OPEN3 *internal;
  int status;


  status = ST_OK;
  internal = (OB_CRYPTO_CONTEXT_OPEN3 *)(signer_key->internal);
  if (signature_info->enc_lth > 0)
    status = eac_decode_signature_parameters(ctx, signature_info, &(internal->sigalg));
  else
    internal->sigalg = signature_info->key_parameters [0];

  switch(internal->sigalg)
  {
  default:
    status = STEAC_BAD_ARG;
    break;
  case EAC_SIG_SHA256:
    hash the message into message_hash
    break;
  };
zzz curve identifier is in one of the key_parameters values.
qqq public key is in the internal structure under public key(?)

  status_lib = uECC_verify(internal->public_key,
    message_hash, hash_size, signature, internal->curve);
  if (status_lib != blah_good)
    status = ST_blah_VERIFY;
  
  return(status);

} /* eac_crypto_verify_signature_ex */
#if 0



#include <stdio.h>
#include <stdlib.h>

#include <eac-encode.h>
#include <eac-crypto_gcm.h>


char log_message [EAC_LOG_BUFFER_MAX];


int eac_crypto_set_key
  (EAC_ENCODE_CONTEXT *ctx,
  EAC_ENCODE_OBJECT *key)
int uECC_valid_public_key(const uint8_t *public_key, uECC_Curve curve);



{ /* eac_crypto_set_key */

  OB_CRYPTO_CONTEXT_GCM *internal;
  int status;
  int status_crypto;


  status = ST_OK;
  if (ctx->verbosity > 3)
  {
    sprintf(log_message, "set_key key length %d. octets\n", key->raw_lth);
    (ctx->eac_log)(log_message);
  };
  if (!(ctx->eac_log))
    status = STEAC_NO_LOGGER;
//  if (key->internal) status = STEAC_MALLOC; // the malloc happens here
  if (!valid_buffer(ctx, key))
    status = STEAC_BUFFER;

  if (status EQUALS ST_OK)
  {
    key->internal = malloc(sizeof(OB_CRYPTO_CONTEXT_GCM));
    if (key->internal EQUALS NULL)
      status = STEAC_MALLOC;
  };
  if (status EQUALS ST_OK)
  {
    internal = key->internal;
    memset(internal, 0, sizeof(OB_CRYPTO_CONTEXT_GCM));

    // apparently this just returns if already done so sprinkling them around?
    aes_init_keygen_tables();

    status_crypto = gcm_setkey(&(internal->gcm_ctx), key->raw, key->raw_lth);
    if (status_crypto != 0)
      status = STEAC_CRYPTO_INIT;
  };
  if (status EQUALS ST_OK)
    key->state_flags = key->state_flags | EACOBJ_STATE_INIT;
  return(status);

} /* eac_crypto_set_key */

#endif

