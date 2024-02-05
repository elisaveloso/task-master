// Testes
TEST_CASE("TaskControllerTest") {
    TaskController controller;
    TaskView view;
    controller.addObserver(&view);

    // Simula a atualização do status da tarefa
    controller.updateTaskStatus(true);

    // Verifica se a GUI foi atualizada corretamente
    // IMPLEMENTE OS TESTES DE ACORDO COM SUAS NECESSIDADES
}