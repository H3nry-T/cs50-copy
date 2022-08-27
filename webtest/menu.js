cont hamburger = document.querySelector(".hamburger");
cont hamburger = document.querySelector(".navList");

hamburger.addEventListener("click", ()=> {
    hamburger.classList.toggle("active");
    navList.classList.toggle("active"); 
});