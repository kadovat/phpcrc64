<?php
dl("crc64.so");
$crc_dec_str = crc64('php', CRC64_DEC_STR);
echo "dec format: " . $crc_dec_str . "\n";
$crc_hex_str = crc64('php', CRC64_HEX_STR);
echo "hex format: " . $crc_hex_str . "\n";
?>
