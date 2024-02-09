# Use an official PHP runtime as a parent image
FROM php:latest

# Set the working directory to /var/www/html
WORKDIR /var/www/html

# Install dependencies
RUN apt-get update && apt-get install -y \
    git \
    unzip \
    libicu-dev \
    zlib1g-dev \
    libzip-dev \
    libpq-dev

# Install PHP extensions
RUN docker-php-ext-configure intl \
    && docker-php-ext-install intl

RUN docker-php-ext-install pdo pdo_pgsql

# Copy the current directory contents into the container at /var/www/html
COPY . /var/www/html

# Install Composer
RUN curl -sS https://getcomposer.org/installer | php -- --install-dir=/usr/local/bin --filename=composer

ENV DATABASE_URL "postgresql://username:password@db:5432/pdb?serverVersion=15&charset=utf8"

# Install Symfony
RUN composer install
RUN curl -sS https://get.symfony.com/cli/installer | bash
RUN mv /root/.symfony*/bin/symfony /usr/local/bin/symfony

# Expose port 8000 for the Symfony web server
EXPOSE 8000

# Start the Symfony web server
CMD ["symfony", "serve", "--no-tls", "--port=8000", "--allow-http"]
