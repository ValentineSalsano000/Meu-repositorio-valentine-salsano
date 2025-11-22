function nextSection(currentSection) {
    // Esconde a seção atual
    const current = document.getElementById(`section${currentSection}`);
    current.classList.remove('active');

    // Mostra a próxima seção
    const next = document.getElementById(`section${currentSection + 1}`);
    if (next) {
        next.classList.add('active');
    }
}

function prevSection(currentSection) {
    // Esconde a seção atual
    const current = document.getElementById(`section${currentSection}`);
    current.classList.remove('active');

    // Mostra a seção anterior
    const prev = document.getElementById(`section${currentSection - 1}`);
    if (prev) {
        prev.classList.add('active');
    }
}

function submitForm() {
    // Lógica para validar e enviar o formulário
    alert('Formulário enviado com sucesso!');
}