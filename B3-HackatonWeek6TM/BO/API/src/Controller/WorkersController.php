<?php
namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Routing\Annotation\Route;
use Symfony\Component\HttpFoundation\Response;
use mysqli;


class WorkersController extends AbstractController
{
    #[Route('/workers/{query?}', name: 'workers')]
    public function workers($query = null): Response
    {
        $conn = new mysqli("localhost", "root", "", "data_base");

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $sql = "SELECT * FROM employees";

        if ($query) {
            parse_str($query, $filters);
            $conditions = [];
            foreach ($filters as $key => $value) {
                $value = $conn->real_escape_string($value);
                $conditions[] = "$key = '$value'";
            }
            $sql .= " WHERE " . implode(' AND ', $conditions);
        }

        $queryRes = $conn->query($sql);

        $result = array();
        if ($queryRes->num_rows > 0) {
            while($row = $queryRes->fetch_assoc()) {
                $result[] = $row;
            }
        } else {
            $result = "0 results";
        }
        $conn->close();

        $response = new Response();

        $response->setContent(json_encode($result, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT));

        $response->setStatusCode(Response::HTTP_OK);

        $response->headers->set('Content-Type', 'application/json');

        $response->headers->set('Access-Control-Allow-Origin', '*');

        return $response;
    }
}