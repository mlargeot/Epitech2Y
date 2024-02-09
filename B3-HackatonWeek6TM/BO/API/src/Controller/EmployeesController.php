<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\Routing\Annotation\Route;

use App\Entity\Employees;
use App\Repository\EmployeesRepository;
use Doctrine\ORM\EntityManagerInterface;
use Symfony\Component\HttpFoundation\Request;


class EmployeesController extends AbstractController
{
    #[Route('/api/v1/employees', name: 'employees_all', methods: ['GET'])]
    public function showAll(EmployeesRepository $employeesRepository, Request $request): JsonResponse
    {
        $employees = $employeesRepository->findAll();
        $employees = array_map(function($employee) { 
            return $employee->toJson($employee);
        }, $employees);
        return $this->json($employees);
    }

    #[Route('/api/v1/employee/{id}', name: 'employee', methods: ['GET'])]
    public function showName(EmployeesRepository $employeesRepository, int $id): JsonResponse
    {
        $employee = $employeesRepository->findOneById($id);
        return $this->json($employee->toJson($employee));
    }
}
