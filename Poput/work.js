let inputjs = document.querySelector('.inputcool');
let buttonjs = document.querySelector('.but');
let vivodjs = document.querySelector('.vivod');
let questionJs = document.querySelector('.question');
buttonjs.addEventListener('click', function(){
	let chislo = inputjs.value;
	if(chislo!=30){
	vivodjs.classList.add('red');
	vivodjs.innerHTML = '15 + 15 это не - ' + chislo;
	}
	else{
		prompt('Вы уверены?');
	}
})
$('.open-popup').click(function(e) {
    e.preventDefault();
    $('.popup-bg').fadeIn(800);
    $('html').addClass('no-scroll');
});

$('.close-popup').click(function() {
    $('.popup-bg').fadeOut(800);
    $('html').removeClass('no-scroll');
});
function Rand1(min,max){
	var chislo = min + Math.random() * ( max - min);
	result = Math.round(chislo);
	return result;
}
function Rand2(min,max){
	var chislo = min + Math.random() * ( max - min);
	result = Math.round(chislo);
	return result;
}
questionJs.addEventListener('mouseover', function(){
	questionJs.style.marginLeft = Rand1(10, 600) + "px";
	questionJs.style.marginRight = Rand2 (10, 400) + "px";
	questionJs.style.marginTop = Rand2 (10, 400) + "px";
})