const steps = [
    "int ft_atoi(const char *str) {",
    "    int i = 0;",
    "    int sign = 1;",
    "    int result = 0;",
    "    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))",
    "        i++;",
    "    if (str[i] == '-' || str[i] == '+') {",
    "        if (str[i] == '-')",
    "            sign = -1;",
    "        i++;",
    "    }",
    "    while (str[i] >= '0' && str[i] <= '9') {",
    "        result = result * 10 + (str[i] - '0');",
    "        i++;",
    "    }",
    "    return (result * sign);",
    "}"
];

const correctOrder = steps.join('\n');

function createBlock(text) {
    const block = document.createElement('div');
    block.className = 'block';
    block.draggable = true;
    block.textContent = text;
    block.addEventListener('dragstart', dragStart);
    block.addEventListener('dragend', dragEnd);
    return block;
}

function dragStart(e) {
    e.dataTransfer.setData('text/plain', e.target.id);
    setTimeout(() => {
        e.target.classList.add('dragging');
    }, 0);
}

function dragEnd(e) {
    e.target.classList.remove('dragging');
}

function createPlaceholder() {
    const placeholder = document.createElement('div');
    placeholder.className = 'placeholder';
    return placeholder;
}

document.addEventListener('DOMContentLoaded', () => {
    const container = document.getElementById('blocks-container');
    steps.forEach((step, index) => {
        const block = createBlock(step);
        block.id = `block-${index}`;
        container.appendChild(block);
    });

    const blocks = document.querySelectorAll('.block');
    blocks.forEach(block => {
        block.addEventListener('dragover', dragOver);
        block.addEventListener('drop', drop);
    });

    container.addEventListener('dragover', dragOverContainer);
    container.addEventListener('drop', dropContainer);
});

function dragOver(e) {
    e.preventDefault();
    const draggingBlock = document.querySelector('.dragging');
    const container = document.getElementById('blocks-container');
    const placeholders = container.querySelectorAll('.placeholder');
    placeholders.forEach(placeholder => placeholder.remove());
    const placeholder = createPlaceholder();
    if (e.target !== draggingBlock) {
        container.insertBefore(placeholder, e.target.nextSibling);
    }
}

function drop(e) {
    e.preventDefault();
    const id = e.dataTransfer.getData('text/plain');
    const draggingBlock = document.getElementById(id);
    const container = document.getElementById('blocks-container');
    container.insertBefore(draggingBlock, e.target.nextSibling);
    const placeholders = container.querySelectorAll('.placeholder');
    placeholders.forEach(placeholder => placeholder.remove());
}

function dragOverContainer(e) {
    e.preventDefault();
}

function dropContainer(e) {
    e.preventDefault();
    const id = e.dataTransfer.getData('text/plain');
    const draggingBlock = document.getElementById(id);
    const container = document.getElementById('blocks-container');
    container.appendChild(draggingBlock);
    const placeholders = container.querySelectorAll('.placeholder');
    placeholders.forEach(placeholder => placeholder.remove());
}

function checkOrder() {
    const container = document.getElementById('blocks-container');
    const blocks = container.querySelectorAll('.block');
    const userOrder = Array.from(blocks).map(block => block.textContent).join('\n');
    const resultDiv = document.getElementById('result');
    if (userOrder === correctOrder) {
        resultDiv.textContent = "¡Función compilada correctamente!";
        resultDiv.style.color = "green";
    } else {
        resultDiv.textContent = "Error: el orden de los bloques es incorrecto.";
        resultDiv.style.color = "red";
    }
}
