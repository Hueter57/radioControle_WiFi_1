
Change these three lines in WebAuthentication.cpp:

  mbedtls_md5_starts(&_ctx);
  mbedtls_md5_update(&_ctx, data, len);
  mbedtls_md5_finish(&_ctx, _buf);
To:

  mbedtls_md5_starts_ret(&_ctx);
  mbedtls_md5_update_ret(&_ctx, data, len);
  mbedtls_md5_finish_ret(&_ctx, _buf);