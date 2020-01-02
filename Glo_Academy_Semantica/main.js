document.addEventListener(`DOMContentLoaded`, () => {
    
    const btnReset = document.getElementById(`reset`),
        btnYes = document.getElementById(`yes`),
        btnNo = document.getElementById(`no`);
        blockQuestion = document.querySelector(`.question`),
        startText = blockQuestion.textContent; 

   const handler = () => {
       let step = 0;
       const questions = [
           `Содержимое в блоке связано по смыслу?`,
           `Содержимое связано по смыслу с остальной страницей?`,
           `Содержимое является самодостаточным?`
       ],
       answer = [`div`,
                `aside`,
                `section`,
                `article`];
       
        return (event) => {
        btnNo.style.display = `inline-block`;

        const theEnd = () => {
            btnYes.style.display = `none`;
            btnNo.style.display = `none`;
            blockQuestion.style.fontSize = `30px`;
            blockQuestion.style.curcor = `pointer`;
            blockQuestion.textContent = `<${blockQuestion.textContent}>`;
            blockQuestion.addEventListener(`click`, init);
        };

        if (event.target === btnYes) {
            blockQuestion.textContent = questions[step];
            if (step === questions.length) {
                blockQuestion.textContent = answer[step];
                theEnd();
            }
        }
        if (event.target === btnNo) {
            blockQuestion.textContent = answer[step-1];
            theEnd();
        }

        step += 1;
       }
   }
   
   let start = handler();

   const init = () => {
       blockQuestion.removeEventListener(`click`, init);
       btnNo.style.display = `none`;
       btnYes.style.display = `inline-block`;
    blockQuestion.textContent = startText;
    blockQuestion.style.fontSize = ``;
    blockQuestion.style.curcor = ``; 
       btnYes.removeEventListener(`click`, start);
       btnNo.removeEventListener( `click`, start);

       start = handler();
      
       btnYes.addEventListener(`click`, start);
       btnNo.addEventListener(`click`, start);
    }
    btnReset.addEventListener(`click`, init);
   init();
})