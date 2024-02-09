<?php

declare(strict_types=1);

namespace DoctrineMigrations;

use Doctrine\DBAL\Schema\Schema;
use Doctrine\Migrations\AbstractMigration;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
final class Version20240117174221 extends AbstractMigration
{
    public function getDescription(): string
    {
        return '';
    }

    public function up(Schema $schema): void
    {
        // this up() migration is auto-generated, please modify it to your needs
        $this->addSql('CREATE TABLE employees (id SERIAL NOT NULL, nom VARCHAR(255) NOT NULL, prenom VARCHAR(255) NOT NULL, poste VARCHAR(255) NOT NULL, equipe VARCHAR(255) NOT NULL, agence VARCHAR(255) NOT NULL, photo_pro VARCHAR(255) DEFAULT NULL, photo_fun VARCHAR(255) DEFAULT NULL, PRIMARY KEY(id))');
        $this->addSql('CREATE TABLE "user" (email VARCHAR(255) NOT NULL, pwd VARCHAR(255) NOT NULL, PRIMARY KEY(email))');
        $this->addSql('INSERT INTO employees SELECT * FROM data_base.employees');
        $this->addSql('INSERT INTO "user" SELECT * FROM data_base.user');
        $this->addSql('DROP TABLE data_base.employees');
        $this->addSql('DROP TABLE data_base."user"');
    }

    public function down(Schema $schema): void
    {
        // this down() migration is auto-generated, please modify it to your needs
        $this->addSql('CREATE SCHEMA public');
        $this->addSql('CREATE SCHEMA data_base');
        $this->addSql('CREATE TABLE data_base.employees (id SERIAL NOT NULL, nom VARCHAR(255) NOT NULL, prenom VARCHAR(255) NOT NULL, poste VARCHAR(255) NOT NULL, equipe VARCHAR(255) NOT NULL, agence VARCHAR(255) NOT NULL, photo_pro VARCHAR(255) DEFAULT NULL, photo_fun VARCHAR(255) DEFAULT NULL, PRIMARY KEY(id))');
        $this->addSql('CREATE TABLE data_base."user" (email VARCHAR(255) NOT NULL, pwd VARCHAR(255) NOT NULL, PRIMARY KEY(email))');
        $this->addSql('DROP TABLE employees');
        $this->addSql('DROP TABLE "user"');
    }
}
