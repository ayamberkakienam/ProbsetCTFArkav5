#!/bin/bash
set -e

if [ "$1" = 'php-fpm' ]; then
    mkdir -p /var/www/public/uploads
    touch /var/www/public/uploads/index.php
    chmod 777 /var/www/public/uploads
fi

exec "$@"