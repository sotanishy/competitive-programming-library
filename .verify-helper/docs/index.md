<br/>

:bangbang: :underage: :bangbang:

This documentation is automatically generated by [online-judge-tools/verification-helper](https://github.com/online-judge-tools/verification-helper)

<button type="button" onclick="expandAll()">Expand All</button> <button type="button" onclick="collapseAll()">Collapse All</button>

<style>
button {
  font: inherit;
  background-color: white;
  color: black;
  border: 2px solid black; /* Green */
}
</style>

<script>
function expandAll() {
  let sections = document.getElementsByTagName('h3');
  for (let i = 0; i < sections.length; i++) {
    let section = sections[i];
    let list = section.nextElementSibling;
    if (list.style.display == 'none') {
      section.click();
    }
  }
}

function collapseAll() {
  let sections = document.getElementsByTagName('h3');
  for (let i = 0; i < sections.length; i++) {
    let section = sections[i];
    let list = section.nextElementSibling;
    if (list.style.display == 'block') {
      section.click();
    }
  }
}

window.addEventListener('load', function(){
  // add a link to GitHub in the header
  let link = document.getElementsByClassName('page-link')[0];
  link.href = 'https://github.com/sotanishy/competitive-programming-library';
  link.textContent = 'GitHub';

  // remove footer
  document.getElementsByTagName('footer')[0].style.display = 'none';

  // toggle sections
  let sections = document.getElementsByTagName('h3');
  for (let i = 0; i < sections.length; i++) {
    let section = sections[i];
    section.textContent = '- ' + section.textContent;
    let list = section.nextElementSibling;
    list.style.display = 'block';
    section.addEventListener('click', function () {
      if (list.style.display == 'none') {
        section.textContent = '- ' + section.textContent.substr(2);
        list.style.display = 'block';
      } else {
        section.textContent = '+ ' + section.textContent.substr(2);
        list.style.display = 'none';
      }
    });
  }
});
</script>