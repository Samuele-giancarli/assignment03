<?php
    $jsonData = file_get_contents('php://input');
    $data = json_decode($jsonData, true);

    $randomLevel = $data['level'];
    $timestamp = $data['timestamp'];

    echo json_encode(['level' => $randomLevel, 'timestamp' => $timestamp]);