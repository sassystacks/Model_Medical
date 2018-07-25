for (var a = [], i = 0; i <= 5; ++i) a[i] = i;

// http://stackoverflow.com/questions/962802#962890
function shuffle(d) {
  for (var c = d.length - 1; c > 0; c--) {
    var b = Math.floor(Math.random() * (c + 1));
    var a = d[c];
    d[c] = d[b];
    d[b] = a;
  }
  return d
};


var Name = ['Luis', 'David', 'Richard', 'Saba', 'Miriam', 'Curt']
var FullName = ['Luis Souto Maior', 'David Tanhelsen', 'Richard Beddoes', 'Saba Aslam', 'Miriam Nightingale', 'Curt Zerr']
var title = ['Machine Whisperer', 'Chief Cheerleader ', 'Mechatronic Loudmouth', 'The Steamroller ', 'The Mechanic ', 'Quality Overlord ']
var description = [

  'Luis has a degree in electrical engineering and is currently pursuing his master\'s in biomedical engineering focusing in training machine learning algorithms to study Alzheimer\'s disease. With over five years of experience in software development for the health industry and academia, Luis brings new perspectives to research and development. Luis develops software, manages the website, and other IT systems bridging the worlds of humans and machines.',

  'Davids\' degree in commerce combined with his passion for diverse challenges have launched him into the vibrant industry of entrepreneurship. As CEO, David will be supporting the team at all steps of growth as well as spreading the company\'s values of transparency, efficiency, and people first. Utilizing over seven years of financial administrative experience, David streamlines Model Medical\'s processes to create a lean and flexible company.',

  'Richard has an undergraduate degree in mechanical engineering and is currently completing a master\'s in biomedical engineering, with a focus in medical image processing. He is often out talking to customers, getting feedback for the team, to help shape their next iteration of an idea. Richard combines knowledge in backend software development with mechanical systems, adding versatility to solution implementation in product development with an emphasis on customer feedback.',

  'Saba has a degree in biochemistry and is currently obtaining her master\'s in biomedical engineering with a focus on stem cell research and tissue engineering. She is passionate about combining her love for science and health with technology and innovation. Saba\'s strong can-do attitude and brutal honesty challenges the team to stay focused and improve their processes.',

  'Miriam has a degree in mechanical engineering and is pursuing her PhD in biomedical engineering with a focus on biomechanics. She brings structure and strategic planning to product and business development. With over six years of technical knowledge and leadership experience, Miriam works under the hood to fine-tune all aspects of Model Medical, ensuring it runs smoothly.',

  'Curt has a degree in Electrical Engineering as well as a technical diploma in Aircraft Maintenance Engineering. His experience in the aerospace industry brings technical skill and quality control to the team. He has a passion for research and design, believing that there is always a solution for any technical problem, big or small. Curt polishes electrical and mechanical systems, ensuring they are customer ready.'
]



var i;
a = shuffle(a);

var code = '<table style="width:100%"> <div class=" card"><tr>';

document.getElementById("person1").innerHTML += code;

for (i = 0; i <= 5; i++) {

  j = a[i]

  if (window.innerWidth > 1000) {


    var code = '<table class = "tab"> <div class=" card"><tr style="text-align:center">  <col width="50"><col width="100"><th><h2>' + FullName[j] + '</h2><img src="' + Name[j] + '_burned.jpg" alt="' + Name[j] + '" class="face"> <div class="container"><p class="title"> ' + title[j] + '   </p><p></p></div></div></th> <th> <div class="description"> <p>' + description[j] + '</p></th></tr></div></table>';
  } else {

    var code = '<table class = "tab"> <div class=" card"><th style="text-align:center">  <col width="100"><col width="100"><tr><h2 style="text-align:center">' + FullName[j] + '</h2><img src="' + Name[j] + '_burned.jpg" alt="' + Name[j] + '" class="face"> <div class="container"><p class="title"> ' + title[j] + '   </p><p></p></div></div></tr> <tr> <div class="description"> <p>' + description[j] + '</p></tr></th></div></table>';
  }
  document.getElementById("person1").innerHTML += code;

}

var code = '</tr></div></table>'

document.getElementById("person1").innerHTML += code;
