cont hamburger = document.querySelector(".hamburger");
cont navList = document.querySelector(".navList");

hamburger.addEventListener("click", ()=> {
    hamburger.classList.toggle("active");
    navList.classList.toggle("active");
});

document.querySelectorAll(".navLink").forEach(n => n.addEventListener("click", () => {
    hamburger.classList.remove("active");
    navList.classList.remove("active");

}))

