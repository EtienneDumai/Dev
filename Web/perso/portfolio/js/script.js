document.addEventListener('DOMContentLoaded', function() {
    // Sélectionne tous les éléments avec les classes 'container', 'image', et 'imageCoteACote'
    const scrollElements = document.querySelectorAll(' .container, .image, .imageCoteACote, footer');

    // Fonction pour vérifier si un élément est visible dans le viewport
    const elementInView = (el, percentageScroll = 100) => {
        const elementTop = el.getBoundingClientRect().top;
        const elementBottom = el.getBoundingClientRect().bottom;

        return (
            (elementTop <= ((window.innerHeight || document.documentElement.clientHeight) * (percentageScroll / 100))) &&
            (elementBottom >= 0)
        );
    };

    // Fonction pour ajouter la classe 'visible' à un élément
    const displayScrollElement = (element) => {
        element.classList.add('visible');
    };

    // Fonction pour enlever la classe 'visible' à un élément
    const hideScrollElement = (element) => {
        element.classList.remove('visible');
    };

    // Fonction pour gérer l'animation au défilement
    const handleScrollAnimation = () => {
        scrollElements.forEach((el) => {
            if (elementInView(el, 100)) {
                displayScrollElement(el);
            } else {
                hideScrollElement(el);
            }
        });
    };

    // Ajoute un écouteur d'événement pour le défilement
    window.addEventListener('scroll', () => {
        handleScrollAnimation();
    });

    // Vérifie initialement quels éléments sont visibles au chargement de la page
    handleScrollAnimation();
});
