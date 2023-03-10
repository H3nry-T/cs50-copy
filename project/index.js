const canvas = document.querySelector("canvas");
const c = canvas.getContext("2d"); //c stands for context it will be used alot

canvas.width = 1024;
canvas.height = 576;

//draw a rectangle canvas from top left coordinate "fighting background"
c.fillRect(0, 0, canvas.width, canvas.height);

//global constants
const gravity = 0.98;

//create new instance of background Sprite();
const background = new Sprite({
    position: {
        x: 0,
        y: 0,
    },
    imageSource: "./assets/img/background.png"
})

const shop = new Sprite({
    position: {
        x: 600,
        y: 130,
    },
    imageSource: "./assets/img/shop.png",
    scale: 2.75,
    framesMax: 6
})

//create instance of PLAYER Sprite
const player = new Fighter({
    position: {
        x: 0,
        y: 0
    },
    velocity: {
        x: 0,
        y: 0
    },
    offset: {
        x: 0,
        y: 0
    },
    imageSource: "./assets/img/samuraiMack/Idle.png",
    framesMax: 8,
    scale: 2.5,
    offset: {
        x: 215,
        y: 157
    },
    sprites: {
        idle: {
            imageSource: "./assets/img/samuraiMack/Idle.png",
            framesMax: 8
        },
        run: {
            imageSource: "./assets/img/samuraiMack/Run.png",
            framesMax: 8
        },
        jump: {
            imageSource: "./assets/img/samuraiMack/Jump.png",
            framesMax: 2
        },
        fall: {
            imageSource: "./assets/img/samuraiMack/Fall.png",
            framesMax: 2
        },
        attack1: {
            imageSource: "./assets/img/samuraiMack/Attack1.png",
            framesMax: 6
        },
        takeHit: {
            imageSource: "./assets/img/samuraiMack/TakeHit-white-silhouette.png", //project/assets/img/samuraiMack/Take Hit - white silhouette.png
            framesMax: 4
        },
        death: {
            imageSource: "./assets/img/samuraiMack/Death.png",
            framesMax: 6
        },
    },
    attackBox: {
        offset: {
            x: 100,
            y: 50,
        },
        width: 155,
        height: 50
    },
    orientation: "RIGHT"
});

player.draw();

//create instance of ENEMY sprite
const enemy = new Fighter({
    position: {
        x: 960,
        y: 0
    },
    velocity: {
        x: 0,
        y: 0
    },
    color: "blue",
    offset: {
        x: -50,
        y: 0
    },
    imageSource: "./assets/img/kenji/Idle.png",
    framesMax: 4,
    scale: 2.5,
    offset: {
        x: 215,
        y: 167
    },
    sprites: {
        idle: {
            imageSource: "./assets/img/kenji/Idle.png",
            framesMax: 4
        },
        run: {
            imageSource: "./assets/img/kenji/Run.png",
            framesMax: 8
        },
        jump: {
            imageSource: "./assets/img/kenji/Jump.png",
            framesMax: 2
        },
        fall: {
            imageSource: "./assets/img/kenji/Fall.png",
            framesMax: 2
        },
        attack1: {
            imageSource: "./assets/img/kenji/Attack1.png",
            framesMax: 4
        },
        takeHit: {
            imageSource: "./assets/img/kenji/Take hit.png",
            framesMax: 3
        },
        death: {
            imageSource: "./assets/img/kenji/Death.png",
            framesMax: 7
        },
    },
    attackBox: {
        offset: {
            x: -165,
            y: 50,
        },
        width: 165,
        height: 50
    },
    orientation: "RIGHT"
});

enemy.draw();

//key bindings
const keys = {
    d: {
        pressed: false
    },
    a: {
        pressed: false
    },
    w: {
        pressed: false
    },
    " ": {
        pressed: false
    },
    ArrowRight: {
        pressed: false
    },
    ArrowLeft: {
        pressed: false
    },
    ArrowUp: {
        pressed: false
    },
    ArrowDown: {
        pressed: false
    }
}

//start the 60 second timer
decreaseTimer();

// animate the game
function animate() {
    // window.requestAnimationFrame(animate);

    //redraw the fighting background as a black rectangle
    c.fillStyle = "black";
    c.fillRect(0, 0, canvas.width, canvas.height);

    //draw in background sprite;
    background.update();

    //draw shop
    shop.update();

    //background opacity
    c.fillStyle = "rgba(255, 255, 255, 0.1)";
    c.fillRect(0, 0, canvas.width, canvas.height);

    //update player's position affected by gravity;
    player.update();
    enemy.update(); //======================================================== RENDER ENEMY

    //default velocity
    player.velocity.x = 0;
    enemy.velocity.x = 0;


    //animation responds to PLAYER controls
    //left, right, idle
    if (keys.a.pressed && player.lastKey === "a") {
        player.velocity.x = -5;
        player.orientation = "LEFT";
        player.switchSprite("run");
    } else if (keys.d.pressed && player.lastKey === "d") {
        player.velocity.x = 5;
        player.orientation = "RIGHT";
        player.switchSprite("run");
    } else {
        //default image
        player.switchSprite("idle");
    }
    //jump
    if (player.velocity.y < 0) {
        player.switchSprite("jump");
    } else if (player.velocity.y > 0) {
        player.switchSprite("fall");
    }

    //animation responds to ENEMY controls (THERE IS AN INVERSION ON X AXIS BUG AND I CANNOT SOLVE)
    if (keys.ArrowLeft.pressed && enemy.lastKey === "ArrowLeft") {
        enemy.velocity.x = -5;
        enemy.orientation = "RIGHT";
        enemy.switchSprite("run");
    } else if (keys.ArrowRight.pressed && enemy.lastKey === "ArrowRight") {
       enemy.velocity.x = 5;
       enemy.orientation = "LEFT";
       enemy.switchSprite("run");
    } else {
        //default image
        enemy.switchSprite("idle");
    }
    //jump
    if (enemy.velocity.y < 0) {
        enemy.switchSprite("jump");
    } else if (enemy.velocity.y > 0) {
        enemy.switchSprite("fall");
    }

    //PLAYER attackBox collision
    if (
        rectangularCollison({rectangle1: player, rectangle2: enemy})
        && player.isAttacking
        && player.framesCurrent === 4
    ) {
        player.isAttacking = false;
        console.log("player attack hit, player can dodge");
        player.canDodge = true;

        //damage enemy health change healthbar
        document.querySelector("#enemy-health").style.width = enemy.health + "%";
        enemy.takeHit(11);
        document.querySelector("#enemy-health").style.width = enemy.health + "%";


    }
    //IF PLAYER misses
    if (player.isAttacking && player.framesCurrent === 4) {
        player.isAttacking = false;
    }

    //ENEMY attackBox collision
    if (
        rectangularCollison({rectangle1: enemy, rectangle2: player})
        && enemy.isAttacking
        && enemy.framesCurrent === 2
    ) {
        enemy.isAttacking = false;
        console.log("enemy attack hit, enemy can dodge");
        enemy.canDodge = true;

         //damage player health change healthbar
         document.querySelector("#player-health").style.width = player.health + "%";
         player.takeHit(9);
         document.querySelector("#player-health").style.width = player.health + "%";
    }

    //IF ENEMY misses
    if (enemy.isAttacking && enemy.framesCurrent === 2) {
        enemy.isAttacking = false;
    }

    //END game based on health
    if (enemy.health <= 0 || player.health <= 0) {
        determineWinner({ player, enemy, timerId });
    }

    window.requestAnimationFrame(animate);
}

animate();


//CONTROLS ===============================================>
//prevent scrolling and browser keybinds
window.addEventListener("keydown", function(e) {
    if(["Space","ArrowUp","ArrowDown","ArrowLeft","ArrowRight"].indexOf(e.code) > -1) {
        e.preventDefault();
    }
}, false);

//button keydown
window.addEventListener("keydown", (event) => {
    if (!player.dead) {
        switch (event.key) {
            //PLAYER controls
            case "d":
                if (Date.now() - player.lastKeyPressTime < 300 && Date.now() - player.lastKeyPressTime > 150) {
                    //DODGE
                    player.dodge();
                    player.canDodge = false;
                }
                keys.d.pressed = true;
                player.lastKey = "d";
                player.lastKeyPressTime = Date.now();
                break;
            case "a":
                if (Date.now() - player.lastKeyPressTime < 300 && Date.now() - player.lastKeyPressTime > 150) {
                    //DODGE
                    player.dodge();
                    player.canDodge = false;
                }
                keys.a.pressed = true;
                player.lastKey = "a";
                player.lastKeyPressTime = Date.now();
                break;
            case "w": ///////////////////
                player.jump();
                break;
            case "s":
                player.attack();
                break;
        }
    }

    if (!enemy.dead) {
        switch (event.key) {
            //ENEMY controls
            case "ArrowRight":
                if (Date.now() - enemy.lastKeyPressTime < 300 && Date.now() - enemy.lastKeyPressTime > 150) {
                    //DODGE
                    enemy.orientation = "RIGHT";
                    enemy.dodge();
                    enemy.canDodge = false;
                }
                keys.ArrowRight.pressed = true;
                enemy.lastKey = "ArrowRight";
                enemy.lastKeyPressTime = Date.now();
                break;
            case "ArrowLeft":
                if (Date.now() - enemy.lastKeyPressTime < 300 && Date.now() - enemy.lastKeyPressTime > 150) {
                    //DODGE
                    enemy.orientation = "LEFT"
                    enemy.dodge();
                    enemy.canDodge = false;
                }
                keys.ArrowLeft.pressed = true;
                enemy.lastKey = "ArrowLeft";
                enemy.lastKeyPressTime = Date.now();
                break;
            case "ArrowUp": ///////////////////
                enemy.jump();
                break;
            case "ArrowDown":
                enemy.attack();
                break;
        }
    }

    if (player.dead || enemy.dead) {
        switch(event.key) {
            case "r":
                location.reload();
                break;
            default:
                break;
        }
    }
});

//button keyup
window.addEventListener("keyup", (event) => {
    switch (event.key) {
        //PLAYER controls
        case "d":
            keys.d.pressed = false;
            break;
        case "a":
            keys.a.pressed = false;
            break;
        case "w":
            keys.w.pressed = false;
            break;

        //ENEMY controls
        case "ArrowRight":
            keys.ArrowRight.pressed = false;
            break;
        case "ArrowLeft":
            keys.ArrowLeft.pressed = false;
            break;
        case "ArrowUp":
            keys.ArrowUp.pressed = false;
            break;
    }
});


