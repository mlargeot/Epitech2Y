<?php

namespace App\Entity;

use App\Repository\EmployeesRepository;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: EmployeesRepository::class)]
class Employees
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column(type: "integer")]
    private ?int $id = null;

    #[ORM\Column(length: 255)]
    private ?string $nom = null;

    #[ORM\Column(length: 255)]
    private ?string $prenom = null;

    #[ORM\Column(length: 255)]
    private ?string $poste = null;

    #[ORM\Column(length: 255)]
    private ?string $equipe = null;

    #[ORM\Column(length: 255)]
    private ?string $agence = null;

    #[ORM\Column(length: 255, nullable: true)]
    private ?string $photo_pro = null;

    #[ORM\Column(length: 255, nullable: true)]
    private ?string $photo_fun = null;

    public function toJson($employee): array
    {
        return [
            "nom" => $employee->getNom(),
            "prenom" => $employee->getPrenom(),
            "poste" => $employee->getPoste(),
            "equipe" => $employee->getEquipe(),
            "agence" => $employee->getAgence(),
            "photo_pro" => $employee->getPhotoPro(),
            "photo_fun" => $employee->getPhotoFun()
        ];
    }

    public function getNom(): ?string
    {
        return $this->nom;
    }

    public function setNom(string $nom): static
    {
        $this->nom = $nom;

        return $this;
    }

    public function getPrenom(): ?string
    {
        return $this->prenom;
    }

    public function setPrenom(string $Prenom): static
    {
        $this->prenom = $prenom;

        return $this;
    }

    public function getPoste(): ?string
    {
        return $this->poste;
    }

    public function setPoste(string $poste): static
    {
        $this->poste = $Poste;

        return $this;
    }

    public function getEquipe(): ?string
    {
        return $this->equipe;
    }

    public function setEquipe(string $equipe): static
    {
        $this->equipe = $equipe;

        return $this;
    }

    public function getAgence(): ?string
    {
        return $this->agence;
    }

    public function setAgence(string $agence): static
    {
        $this->agence = $agence;

        return $this;
    }

    public function getPhotoPro(): ?string
    {
        return $this->photo_pro;
    }

    public function setPhotoPro(string $photo_pro): static
    {
        $this->photo_Pro = $photo_pro;

        return $this;
    }

    public function getPhotoFun(): ?string
    {
        return $this->photo_fun;
    }

    public function setPhotoFun(?string $photo_fun): static
    {
        $this->photo_fun = $photo_fun;

        return $this;
    }
}
