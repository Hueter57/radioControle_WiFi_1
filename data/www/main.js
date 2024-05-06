// $.ajaxSetup({ timeout: 1000 });
// function Send(btn) {
//     $.get('/' + btn);
//     { Connection: close };
// }



const value = document.querySelector("#valuee");
const input = document.querySelector("#sliderr");
// value.textContent = input.value;
input.addEventListener("input", (event) => {
    value.textContent = event.target.value;

    var data = {
        x : event.target.value
    }
    var send_json = JSON.stringify(data);

    const xhr = new XMLHttpRequest()
    xhr.open("POST","/send",true)
    xhr.setRequestHeader("Content-Type", "application/json")
    xhr.timeout = 5000
    xhr.send(send_json)
    console.log(send_json)
});


let joystickBall;
let joystickCenterX;
let joystickCenterY;
let joystickLimitNumber = 35;

const init = () => {
    setupJoystick();
};

const setupJoystick = () => {
    joystickBall = document.getElementById("joystick-ball");
    joystickCenterX =
        joystickBall.getBoundingClientRect().left + joystickBall.clientWidth / 2;
    joystickCenterY =
        joystickBall.getBoundingClientRect().top + joystickBall.clientHeight / 2;
    joystickBall.addEventListener("touchmove", dragMove);
    joystickBall.addEventListener("touchend", dragLeave);
};

const dragMove = (event) => {
    event.preventDefault();

    const pageX = event.touches[0].pageX;
    const pageY = event.touches[0].pageY;

    // const pageX = event.clientX;
    // const pageY = event.clientY;
    let touchX, touchY;
    console.log(Math.pow(pageX - joystickCenterX, 2));
    if (Math.pow(pageX - joystickCenterX, 2) + Math.pow(pageY - joystickCenterY, 2) < Math.pow(joystickLimitNumber, 2)) {
        touchX = pageX - joystickCenterX;
        touchY = pageY - joystickCenterY;
    } else {
        const distance = Math.floor(Math.sqrt(Math.pow(pageX - joystickCenterX, 2) + Math.pow(pageY - joystickCenterY, 2)));
        console.log("distance:" + distance);
        touchX = (pageX - joystickCenterX) * joystickLimitNumber / distance;
        touchY = (pageY - joystickCenterY) * joystickLimitNumber / distance;
    }

    console.log(touchX, touchY);
    joystickBall.style.left = `calc(50% + ${touchX}px)`;
    joystickBall.style.top = `calc(50% + ${touchY}px)`;
};

const dragLeave = () => {
    joystickBall.style.top = "50%";
    joystickBall.style.left = "50%";
};

init();

window.addEventListener("resize", () => {
    joystickCenterX =
        joystickBall.getBoundingClientRect().left + joystickBall.clientWidth / 2;
    joystickCenterY =
        joystickBall.getBoundingClientRect().top + joystickBall.clientHeight / 2;
});