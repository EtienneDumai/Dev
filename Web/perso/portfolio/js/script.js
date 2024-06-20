document.addEventListener('DOMContentLoaded', function() {
    // Attend que le DOM soit entièrement chargé avant d'exécuter le script
    const scrollElements = document.querySelectorAll('.container, .image, .imageCoteACote');
    // Sélectionne tous les éléments avec les classes 'container', 'image', et 'imageCoteACote'

    const elementInView = (el, percentageScroll = 100) => {
        // Fonction pour vérifier si un élément est visible dans le viewport
        const elementTop = el.getBoundingClientRect().top;
        // Position du haut de l'élément par rapport au viewport
        const elementBottom = el.getBoundingClientRect().bottom;
        // Position du bas de l'élément par rapport au viewport

        return (
            (elementTop <= ((window.innerHeight || document.documentElement.clientHeight) * (percentageScroll / 100))) &&
            (elementBottom >= 0)
        );
        // Retourne true si l'élément est visible dans le viewport (partiellement ou totalement)
    };

    const displayScrollElement = (element) => {
        // Fonction pour ajouter la classe 'visible' à un élément
        element.classList.add('visible');
    };

    const hideScrollElement = (element) => {
        // Fonction pour enlever la classe 'visible' à un élément
        element.classList.remove('visible');
    };

    const handleScrollAnimation = () => {
        // Fonction pour gérer l'animation au défilement
        scrollElements.forEach((el) => {
            // Pour chaque élément dans scrollElements
            if (elementInView(el, 75)) {
                // Si l'élément est visible dans le viewport à 75%
                displayScrollElement(el);
                // Ajouter la classe 'visible'
            } else {
                hideScrollElement(el);
                // Enlever la classe 'visible' si l'élément n'est plus visible
            }
        });
    };

    window.addEventListener('scroll', () => {
        // Ajoute un écouteur d'événement pour le défilement
        handleScrollAnimation();
        // Exécute handleScrollAnimation à chaque fois que l'utilisateur fait défiler la page
    });

    handleScrollAnimation();
    // Vérifie initialement quels éléments sont visibles au chargement de la page
});
